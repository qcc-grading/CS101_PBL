# Inginious problem set under COERS

This repository contains the list of c++ problems set.

## Extra info.

To use this repository you need to install [Inginious](https://inginious.readthedocs.io/en/v0.5/) and [INGInious-problem-custom plugin](https://github.com/UCL-INGI/INGInious-problems-custom). Unfortunately, there is a bug on INGInious-problem-custom plugin. You shoud manually copy `static` and `templates` folders into the installed plugin folder.

For example, if you use `python3.5`, you  may copy it using this code.
```
cd /usr/lib/python3.5/site-packages/inginious-problems-custom
sudo svn export https://github.com/qccmathcs/INGInious-problems-custom.git/trunk/inginious-problems-custom/static
sudo svn export https://github.com/qccmathcs/INGInious-problems-custom.git/trunk/inginious-problems-custom/templates
```

You also need to update `configuration.yaml`.

```
plugins:
  - plugin_module: "inginious-problems-custom"
```

## custom docker image

Using `build.sh` and `Dockerfile`, you need to build a custom docker image with the `e2e` tag. This image contains `c++` and `pexpect` module.

This project is supported under COERS Grant.
