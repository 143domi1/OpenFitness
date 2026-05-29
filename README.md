# OpenFitness

**OpenFitness** is a free and open source fitness application to track your health!  
It currently only supports **water tracking**,**weight tracking** and **steps tracking** , in the future more features will come.  
Try it if you care about your **health!**

---

## How to compile?

First of all, you need to download the repo.

```bash
wget https://github.com/143domi1/OpenFitness
```

I have only compiled this app with the g++ compiler, but it probably works with other compilers too.  
This app works both as a dynamic or static executable.  
(Dynamic means the app does not come with the libaries, while Static means the libaries are packaged into the app)

---

### To compile it for dynamic use:

```bash
g++ main.cpp -o openfitness
```

---

### Required **Libarys** for this application:

```
linux-vdso.so.1 (0x00007f9f2e01f000)
libstdc++.so.6 => /usr/lib/libstdc++.so.6 (0x00007f9f2dc00000)
libm.so.6 => /usr/lib/libm.so.6 (0x00007f9f2dafa000)
libgcc_s.so.1 => /usr/lib/libgcc_s.so.1 (0x00007f9f2df68000)
libc.so.6 => /usr/lib/libc.so.6 (0x00007f9f2d800000)
/lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007f9f2e021000)
```

---

### To compile it for Static use:

```bash
g++ main.cpp -o openfitness -static
```

---

## Download

If you don't want to bother with compiling, you can download it in the releases section.

---

## Bugs

You can report bugs you found in the app in **Issues**

---

## Contribute

To contribute to this application, you need to fork the repo  
then add what you want in the code , and then make a pull request.  
If you do not understand, you can use the Github Standard for contributing.
