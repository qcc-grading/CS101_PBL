from e2e import e2e, check_maker,make
import os
#from utest import utest

os.chdir("stu")

codename='code1'
template='code1.cc.tpl'
ext="cc"
tag_num="1"
tag="add_function"
order=[{'expect': ':', 'send': 'a'}, {'expect': ':', 'send': 'Curry'}, {'expect': ':', 'send': 'L'}, {'expect': ':', 'send': 'n'}, {'expect': ':', 'send': 'b'},{'expect': ':', 'send': 'd'}]
ans="ans1"
e2etest=True

make(ans)
check=check_maker(ans,order)
print(check)
#scores[0]=utest(template,codename,ext,tag_num,tag,e2etest,order,check)

# subprocess.run("rm -rf *. *.cc *.tpl *.h *.o", shell=True)

