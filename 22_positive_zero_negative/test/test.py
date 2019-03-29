#pexpect part E2E
import pexpect as px
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
            print("retcode==0")
            return "Failure"
        elif child.after is not None:
            output=''.join(child.before.decode("utf-8").split())
        print("output:",output)
        if order['check'] == output:
            print("next!")
            continue
        else:
            print("not same: fail!")
            return "Failure"
    return "Success"
### We ignore spaces.
orders=[{'expect':'integer:','send':'7','check':'7POSITIVE'},{'expect':'integer:','send':'0','check':'0ZERO'},{'expect':'integer:','send':'-9','check':'-9NEGATIVE'}]
result=e2e('student_code',orders)
score = 0
if result == "Success":
    score = 100
else: # Fail
    score = 0
print(score)