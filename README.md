# TCP - UDP: Client - Server application
## About
Authors:
- Yehor Korotenko (yehor.korotenko@etu-upsaclay.fr)
- Ivan Kharkov (ivan.kharkov@etu-upsaclay.fr)

This project was done for networking course during the third semester on double-degree bachelor (Math - Computer Scince) at the **Paris Saclay University**

## Setup
1. Make sure you have make installed
2. Make sure you have gcc compiler installed
3. Make sure you have 9600 availiable or change it in each file
3. Enter to the directory you wish:
- `cd tcp`
- `cd udp`
4. Run `make all` command to compile client and server
5. Run `./serv` then run `./cli` and you'll see how the program works (**the order matters!**)
6. To clean all the executables and additional directories, run: `make clean`

## Project overview
```
├── README.md
├── tcp 
│   ├── Makefile
│   ├── client
│   │   └── main.c
│   └── server
│       └── main.c
└── udp 
    ├── Makefile
    ├── client
    │   └── main.c
    └── server
        └── main.c
```

There are two main directories:
- `tcp` with client - server application build using **TCP** protocol
- `udp` with client - server application build using **UDP** protocol

Inside of each directory there's a file `Makefile` to make the process of build the application easier and two directories:
- `client` with client side application
- `server` with server side application

In each directory there's a `main.c` file that contains all the logic of each program.

