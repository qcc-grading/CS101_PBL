import pexpect as px
import subprocess, shlex, re, os, yaml
p = subprocess.Popen(shlex.split("make answer"), stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
make_output = p.communicate()[0].decode('utf-8')
print(make_output)
def e2e(name, orders, timeout=5):       
    for order in orders:
        child = px.spawn('./'+name)
        #child.delaybeforesend = 0
        output=''
        # if order is not empty, 
        if order['expect']:
            child.expect(order['expect'])
        if order['send']:
            child.sendline(order['send'])
        retcode = child.expect([px.TIMEOUT, px.EOF],timeout)
        if retcode==0:
            #print("retcode==0")
            return "Failure"
        elif child.after is not None:
            output=''.join(child.before.decode("utf-8").split())
        print("output:",output)
        if order['check'] == output:
            continue
        else:
            return "Failure"
    return "Success"
import random
ri=random.randint(-100,100)
rsend=str(ri)
rcheck=rsend+"Theansweris"+str(ri+1)+"!"

orders=[{'expect':'integer:','send':'5','check':'5Theansweris6!'},{'expect':'integer:','send':'-9','check':'-9Theansweris-8!'},{'expect':'integer:','send':rsend,'check':rcheck}]
result=e2e('answer',orders)
print(result)