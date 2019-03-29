FROM  ingi/inginious-c-base
LABEL org.inginious.grading.name="e2e"
RUN   yum install -y gcc cpp make binutils libstdc++ && yum clean all
RUN pip3.5 install pexpect