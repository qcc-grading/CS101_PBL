import pexpect as px
def e2e(name, order, timeout=5):      
    child = px.spawn('./python3 '+name)
    #child.delaybeforesend = 0
    output=''
    # if order is not empty,  
    if order['expect']:
        child.expect(order['expect'])
    if order['send']:
        child.sendline(order['send'])
    retcode = child.expect([px.TIMEOUT, px.EOF],timeout)
    if retcode==0:
        return "Failure"
    elif child.after is not None:
        output=''.join(child.before.decode("utf-8").split())
    print(output)
    if order['check'] == output:
        return "Success"
    else:
        return "Failure"
order={'expect':'integer:','send':'5','check':'56'}
print(e2e('one.py',order))
