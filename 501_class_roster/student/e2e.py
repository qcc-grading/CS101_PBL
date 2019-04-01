import pexpect as px
import subprocess, shlex, re
import sys

def make(codename):
    p = subprocess.Popen(shlex.split("make "+codename), stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
    make_output = p.communicate()[0].decode('utf-8')
    return p.returncode, make_output

def e2e(runner,order=[],check=[]):    
    clean=lambda st: "".join(st.split())
    output_begin=lambda child, send=None: clean(child.before+child.after)
    output=lambda child, send: clean(child.before+(child.after if child.after else "" ) )[(len(clean(send)) if send else 0):]
    output_end=lambda child, send: clean(child.before)[len(clean(send)):]
    n=len(order)
    child=px.spawn('./'+runner, encoding='utf-8')
    assert(n+1==len(check))
    if n==0:
        child.expect([px.TIMEOUT, px.EOF],timeout=1)
        return [output_begin(child)==check[0]]
    #n>=1
    record=[False]*(n+1)
    expect=order[0]['expect']
    child.expect(expect)
    record[0]=output_begin(child)==check[0]
    for i in range(1,n):
        send=order[i-1]['send']
        expect=order[i]['expect']
        child.sendline(send)
        child.expect(expect)
        record[i]=(output(child,send)==check[i])
    send=order[n-1]['send']
    child.sendline(send)
    child.expect([px.TIMEOUT, px.EOF],timeout=1)
    record[n]=(output_end(child,send)==check[n])
    return record

def check_maker(runner,order=[]):
    clean=lambda st: "".join(st.split())
    output_begin=lambda child, send=None: clean(child.before+child.after)
    output=lambda child, send: clean(child.before+(child.after if child.after else "" ) )[(len(clean(send)) if send else 0):]
    output_end=lambda child, send: clean(child.before)[len(clean(send)):]
    n=len(order)
    child=px.spawn('./'+runner, encoding='utf-8')
    if n==0:
        child.expect([px.TIMEOUT, px.EOF],timeout=1)
        return [output_begin(child)]
    #n>=1
    record=[False]*(n+1)
    expect=order[0]['expect']
    child.expect(expect)
    record[0]=output_begin(child)
    for i in range(1,n):
        send=order[i-1]['send']
        expect=order[i]['expect']
        child.sendline(send)
        child.expect(expect)
        record[i]=(output(child,send))
    send=order[n-1]['send']
    child.sendline(send)
    child.expect([px.TIMEOUT, px.EOF],timeout=1)
    record[n]=(output_end(child,send))
    return record
