#!/usr/bin/python2
import sys,os,pdb

def getTextFromFiles(fileName):
    l = []
    i = 0
    with open(fileName,"r") as fileobject:
        for line in fileobject:
            l.append(line)
    return l

if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit('Usage: script.py file-name')
    if not os.path.exists(sys.argv[1]):
        sys.exit('ERROR: file %s not found!' % sys.argv[1])

    l =  getTextFromFiles(sys.argv[1])
    #print(l)
    z = l
    f = open("parsed.txt","w")
    for line in l:
        line = line.translate(None,"\n")
        f.write("#include \"%s\"\n" % line)
    for line in z:
        line = line.translate(None,"\n")
        f.write("%%include \"%s\"\n" % line)
    f.close()
