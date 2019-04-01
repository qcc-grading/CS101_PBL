import pexpect as px
import sys
# Switch working directory to student/
#os.chdir("student")]
order=[]
clean=lambda st: "".join(st.split())
output_begin=lambda child, send=None: clean(child.before+child.after)
output=lambda child, send: clean(child.before+(child.after if child.after else "" ) )[(len(clean(send)) if send else 0):]
output_end=lambda child, send: clean(child.before)[len(clean(send)):]
child = px.spawn('./code1', encoding='utf-8')
child.logfile = sys.stdout
check=[]
expect=":"
child.expect(expect)
check.append(output_begin(child))
send="a"
order.append({'expect':expect,'send':send})
child.sendline(send)
expect=":"
child.expect(expect)
check.append(output(child,send))
send="Curry"
order.append({'expect':expect,'send':send})
child.sendline(send)
expectr="attendances(A,L,E,P):"
child.expect(expect)
check.append(output(child,send))
send=r"L"
order.append({'expect':expect,'send':send})
child.sendline(send)
expect=r":"
child.expect(expect)
check.append(output(child,send))
send="n"
order.append({'expect':expect,'send':send})
child.sendline(send)
expect=r":"
child.expect(expect)
check.append(output(child,send))
send="d"
order.append({'expect':expect,'send':send})
child.sendline(send)
child.expect([px.TIMEOUT, px.EOF],timeout=1)
check.append(output_end(child,send))
print("order=",order,sep='')
print("check=",check,sep='')
