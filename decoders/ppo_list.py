"""Labelled listing of a Freedom Fighters .ppo script with its parents resolved.
Usage: python3 -I ppo_list.py <scripts_dir> <rel/path.ppo> [outfile]
       python3 -I ppo_list.py --all <scripts_dir> <out_dir>
Parents are found from the '..\\X.sdl' names in the file's serialized prefix.
See opcodes.md."""
import struct,sys,re,os
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
import ppo_dis as P

def header(path):
    d=open(path,'rb').read(); k=d.find(b'\x00\x00\x80\x3f')
    h=struct.unpack_from('<I f I I 4H 16s 16s 6I 12I',d,k-4)
    return d,k,h

def parent_of(path):
    d,k,h=header(path)
    names=re.findall(rb'[A-Za-z0-9_\\.]+\.sdl',d[:k])
    return names[0].decode().split('\\')[-1][:-4] if len(names)>=2 else None

def find(scripts,name):
    for root,_,fs in os.walk(scripts):
        for f in fs:
            if f.lower()==name.lower()+'.ppo': return os.path.join(root,f)

def chain(scripts,path):
    out=[]; p=parent_of(path)
    while p:
        pp=find(scripts,p)
        if not pp: out.append(('MISSING',p)); break
        out.append((pp,p)); p=parent_of(pp)
    return out

def states(path):
    """state names (by string id order) -> entry address, from the o70 table"""
    d,k,h=header(path); L=P.load(path); b=L['blob']; o70=h[16:28][2]
    w=struct.unpack_from('<7I',b,o70); n=w[2]
    if n==0 or n>1000: return {}
    addrs=struct.unpack_from('<%dI'%n,b,o70+28)
    me=os.path.basename(path)[:-4]
    names=[s for i,s in sorted(L['strings'].items()) if s.startswith(me+'.')]
    if len(names)!=n: names=(names+['state%d'%i for i in range(n)])[:n]
    return dict(zip(addrs,names))

def vtable(path):
    d,k,h=header(path); b=P.load(path)['blob']; o6c=h[16:28][1]
    n=struct.unpack_from('<I',b,o6c)[0]
    return list(struct.unpack_from('<%dI'%n,b,o6c+4))

def listing(scripts,path):
    ch=chain(scripts,path)
    S={}
    for pp,_ in reversed(ch):
        if pp!='MISSING': S.update(P.load(pp)['strings'])
    L=P.load(path); S.update(L['strings']); base=L['base']
    st=states(path); vt=vtable(path)
    fnlab={a:'fn#%d'%i for i,a in enumerate(vt) if base<=a<base+len(L['code'])}
    out,pc,ok=P.dec(L['code'])
    lines=['; %s'%path,'; parents: %s'%(' -> '.join(n for _,n in ch) or 'none'),
           '; code base %#x, %d bytes, decode %s'%(base,len(L['code']),'clean' if ok else 'FAIL'),
           '; states: %d   vtable: %d entries (own: %d)'%(len(st),len(vt),len(fnlab)),'']
    sub=lambda a: re.sub(r'str#(\d+)',lambda m:'"%s"'%S.get(int(m.group(1)),'?str%s'%m.group(1)),a)
    def tgt(a):
        return re.sub(r'@(0x[0-9a-f]+)',lambda m:'@'+st.get(int(m.group(1),16),m.group(1)),a)
    for r in out:
        a=base+r[0]
        if a in st: lines+=['','STATE %s:'%st[a]]
        if a in fnlab: lines+=['','FUNC %s:'%fnlab[a]]
        if a==base: lines+=['CONSTRUCTOR:']
        args=r[2]
        if r[1] in ('SETSTATE','SETSTARTSTATE','SETSTATE_V'):
            v=int(args,16); args='%s (%s)'%(args,st.get(v,'?'))
        lines.append('  %05x  %-14s %s'%(a,r[1],tgt(sub(args))))
    return lines,ok

if __name__=='__main__' and sys.argv[1]=='--all':
    # python3 -I ppo_list.py --all <scripts_dir> <out_dir>: one .lst per script
    scripts,outd=sys.argv[2],sys.argv[3]
    for root,_,fs in os.walk(scripts):
        for f in sorted(fs):
            if not f.endswith('.ppo'): continue
            src=os.path.join(root,f); rel=os.path.relpath(src,scripts)
            rel=re.sub(r'^alllevels(?=/)','AllLevels',rel,flags=re.I)  # ZGFs mix AllLevels/Alllevels/alllevels; one folder on case-insensitive disks
            dst=os.path.join(outd,rel[:-4]+'.lst'); os.makedirs(os.path.dirname(dst),exist_ok=True)
            lines,ok=listing(scripts,src); open(dst,'w').write('\n'.join(lines)+'\n')
            print('clean' if ok else 'FAIL', rel, len(lines))
elif __name__=='__main__':
    lines,ok=listing(sys.argv[1],sys.argv[2])
    if len(sys.argv)>3: open(sys.argv[3],'w').write('\n'.join(lines)+'\n')
    else: print('\n'.join(lines))
