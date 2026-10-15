import struct
from pilot import S
from recruits_util import rnd,clear_hooks,hook_rec,pystub

def gen(c):
 clear_hooks(c);r=c.rng;e=c.emu
 def string(p):
  b=bytearray()
  while e.rbytes(p+len(b),1)!=b'\0':b.extend(e.rbytes(p+len(b),1))
  return bytes(b)
 filename=rnd(c,64);e.wbytes(filename,b'C:\\game\\worker.cpp\0');buffer=rnd(c,128);e.wbytes(buffer+20,b'symbol_name\0');e.w32(0x6e4084,buffer)
 e.w32(0x6fcd80,r.getrandbits(32));e.w32(0x6fcd7c,r.choice([0,1,2,3]));hook_rec(c,0x41dd90,0,this=True)
 def fill(em,k):em.wbytes(em.arg32(0),bytes([em.arg32(1)&255])*em.arg32(2))
 hook_rec(c,0x634d10,3,pop=0,stackmark=(0,),side=fill)
 def module(em,k):
  p=em.arg32(2);em.calllog.append(('module-size',em.r32(p)));em.wbytes(p+28,b'game_module\0')
 e.w32(0x6fcd64,pystub(c,3,stackmark=(2,),side=module,ret=r.randrange(2)))
 def context(em,k):
  p=em.arg32(3);em.calllog.append(('context-initial',em.rbytes(p,20)));em.w32(p+8,rline);em.w32(p+12,filename);em.w32(em.arg32(2),line)
 rline=r.getrandbits(32);line=r.randrange(1000)
 e.w32(0x6fcd5c,pystub(c,4,stackmark=(2,3),side=context,ret=r.randrange(2)))
 e.w32(0x6fcd6c,pystub(c,4,stackmark=(2,),ret=r.randrange(2)))
 e.w32(0x67609c,pystub(c,0,ret=r.getrandbits(32)));e.w32(0x6760ac,pystub(c,0,ret=r.getrandbits(32)));e.w32(0x6fcd54,pystub(c,1))
 def fmt(em,k):
  em.calllog.append(('format-name',string(em.arg32(2))));em.wbytes(em.arg32(0),b'worker.cpp:line\0')
 e.w32(0x6761e4,pystub(c,5,pop=0,stackmark=(0,),side=fmt))
 def report(em,k):
  form=em.arg32(0);em.calllog.append(('report-module',string(em.arg32(1))))
  em.calllog.append(('report-text',string(em.arg32(4) if form==0x677078 else em.arg32(3))))
 hook_rec(c,0x41e010,4,pop=0,stackmark=(1,3),side=report)
 hook_rec(c,0x7003b0,0,pop=0,ret=r.getrandbits(32))
 return [r.getrandbits(32)]
S(0x41d540,'GUESS report thread symbol location','thiscall',None,ret=None,gen=gen)
