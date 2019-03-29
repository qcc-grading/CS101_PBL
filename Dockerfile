FROM  ingi/inginious-c-base
LABEL org.inginious.grading.name="e2e"
RUN yum install -y gcc gcc-c++ gdb cpp make cmake valgrind binutils libstdc++ clang clang-analyzer clang-devel llvm automake check check-devel CUnit CUnit-devel zlib-devel openssl-devel time jansson-devel graphviz graphviz-devel cppcheck && yum clean all
RUN pip3.5 install pexpect