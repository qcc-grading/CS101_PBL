import subprocess, shlex, re
from inginious import feedback, rst, input
from e2e import make
import sys

def utest(template,codename,ext,tag_num,tag,e2etest=False,order=[],check=[]):
    # Fetch and save the student code into a file for compilation
    input.parse_template(template, codename+"."+ext)

    # Compilation
    returncode, make_output = make(codename)
    # If compilation failed, exit with "failed" result
    if returncode:
        feedback.set_tag("[{}] {}:not_compile".format(tag_num,tag), True)
        feedback.set_global_result("[{}] {}: failed".format(tag_num,tag))
        feedback.set_global_feedback("[{}] {}: The compilation of your code has failed. Please see the exit message of ``make`` command:".format(tag_num,tag))
        feedback.set_global_feedback(rst.get_codeblock('', make_output), True)
        exit(0)
    # Remove source files
    subprocess.run("rm -rf *.c *.tpl *.h *.o", shell=True)

    LANG = input.get_input('@lang')
    # Run a code
    score = 0
    if e2etest==True: # you need order, check
        result ="Success"  if all(e2e(codename,order,check)) else "Failure"
    else:
        p = subprocess.Popen(shlex.split("run_student --time 20 --hard-time 60 ./{} LANGUAGE={}".format(codename,LANG)), stderr=subprocess.STDOUT, stdout=subprocess.PIPE)
        o, e = p.communicate()
        result=o.decode("utf-8")
    if result == "Success":
        score = 100
    else: # Fail
        score = 0
    return score

def ureport(scores):
    avg=round(sum(scores)/len(scores))
    feedback.set_grade(avg)
    feedback.set_global_result("success" if avg >=90  else "failed")
    scores_list="["+(",".join([str(s) for x in scores])+"]"
    feedback.set_global_feedback("The list of scores of each question is "+scores_list+".")

        
