package main

import (
	"fmt"
	"net"
)

func main() {

	addr,err := net.ResolveUDPAddr("udp",":30000")
    CheckError(err)

	sockln, err := net.ListenUDP("udp", addr)
	CheckError(err)

	buf := make([]byte, 1024)

	for {
		n, addr, err := sockln.ReadFromUDP(buf)
		CheckError(err)
		fmt.Println("Received: ", buf[0:n], "\nAddress: ", addr, "\n")
		_ = addr
		
	}	
}

func CheckError(err error){
	if err != nil {
		// something
	}
}
