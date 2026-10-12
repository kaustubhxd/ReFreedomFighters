"""Minimal Xbox XDVDFS (XISO / redump XGD) lister/extractor. Stdlib only.
Usage: python3 -I xiso.py image.iso                -> list all files with sizes
       python3 -I xiso.py image.iso outdir pat...  -> extract files whose path matches any regex pat
"""
import struct,sys,os,re
MAGIC=b'MICROSOFT*XBOX*MEDIA'
def find_base(f):
    for base in (0,0x18300000,0x2080000,0xFD90000):
        f.seek(base+0x10000)
        if f.read(20)==MAGIC: return base
    raise SystemExit('no XDVDFS volume descriptor found')
def walk(f,base,sec,size,prefix=''):
    f.seek(base+sec*2048); d=f.read(size); out=[]; stack=[0]; seen=set()
    while stack:
        o=stack.pop()
        if o in seen or o+14>len(d): continue
        seen.add(o)
        l,r,s,n,a,nl=struct.unpack_from('<HHIIBB',d,o)
        if l==0xFFFF: continue
        name=d[o+14:o+14+nl].decode('latin-1'); p=prefix+'/'+name
        if l: stack.append(l*4)
        if r: stack.append(r*4)
        if a&0x10:
            if n: out+=walk(f,base,s,n,p)
        else: out.append((p,base+s*2048,n))
    return out
f=open(sys.argv[1],'rb'); base=find_base(f)
f.seek(base+0x10000+20); rs,rz=struct.unpack('<II',f.read(8))
files=sorted(walk(f,base,rs,rz))
if len(sys.argv)<3:
    for p,o,n in files: print('%12d  %s'%(n,p))
    print('files:',len(files),'image base',hex(base))
else:
    pats=[re.compile(x,re.I) for x in sys.argv[3:]]
    for p,o,n in files:
        if any(x.search(p) for x in pats):
            dst=os.path.join(sys.argv[2],p.lstrip('/')); os.makedirs(os.path.dirname(dst),exist_ok=True)
            if os.path.exists(dst): print('exists, skipped',dst); continue
            f.seek(o); open(dst,'wb').write(f.read(n)); print('extracted',p,n)
