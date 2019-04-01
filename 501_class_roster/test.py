import subprocess, shlex, re, os, yaml
import sys
#import inginious
import pexpect as px
# Switch working directory to student/
#os.chdir("student")]
def e2e(codename, orders, timeout=3): 
    #results=[]      
    for order in orders:
        child = px.spawn('./'+codename, encoding='utf-8')
        #child.logfile = sys.stdout
        output=''
        for task in order: 
            if task['expect']:
                child.expect(task['expect'])
                print("expect before:",child.before)
                print("expect after:",child.after)
                output+=child.after
            if task['send']:
                child.sendline(task['send'])
        print("output:", output)
        retcode = child.expect([px.TIMEOUT, px.EOF],timeout=5)

        #results.append(result)
    #if all(results):
    #   return "Success" 
    # else:
    #   return "Failure"   
    return "Success"
def test(template,codename,tag_num,tag,e2etest=False,orders=[[]]):
    # Fetch and save the student code into a file for compilation
    #inginious.input.parse_template(template, codename+".cc")

    # Compilation
    p = subprocess.Popen(shlex.split("make "+codename), stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
    make_output = p.communicate()[0].decode('utf-8')
    # If compilation failed, exit with "failed" result
    if p.returncode:
        #inginious.feedback.set_tag("[{}] {}:not_compile".format(tag_num,tag), True)
        #inginious.feedback.set_global_result("[{}] {}: failed".format(tag_num,tag))
        #inginious.feedback.set_global_feedback("[{}] {}: The compilation of your code has failed. Please see the exit message of ``make`` command:".format(tag_num,tag))
        #inginious.feedback.set_global_feedback(inginious.rst.get_codeblock('', make_output), True)
        print("Compile error.")
        exit(0)
    # Remove source files
    subprocess.run("rm -rf *.c *.tpl *.h *.o", shell=True)

    #LANG = inginious.input.get_input('@lang')
    # Run a code
    score = 0
    if e2etest==True:
        result=e2e(codename,orders)
    else:
        #p = subprocess.Popen(shlex.split("run_student --time 20 --hard-time 60 ./{} LANGUAGE={}".format(codename,LANG)), stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
        p = subprocess.Popen(shlex.split("./{}".format(codename)), stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
        o, e = p.communicate()
        result=o.decode("utf-8")
    if result == "Success":
        score = 100
    else: # Fail
        score = 0
    return score

scores=[]
orders1=[[{'expect':r'(a,b,c,d):','send':'a','check':'a'},{'expect':r'tudent:','send':'Curry','check':'a'}]]
score1=test(template="code1.cc.tpl",codename="code1",tag_num="1",tag="add_function",e2etest=True,orders=orders1)
print(score1)
#avg=round(sum(scores)/len(scores))
#inginious.feedback.set_grade(avg)
#inginious.feedback.set_global_result("success" if avg >= 100 else "failed")
#inginious.feedback.set_global_feedback("The list of scores of each test is "+str(scores)+".")