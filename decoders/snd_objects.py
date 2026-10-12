"""List every sound object (ZSNDOBJ, GMS class 0x200012) of a scene with its own/event data
and the SND record it plays. Usage: python3 decoders/snd_objects.py <scene>.GMS <scene>.SND out.json
Field meanings: see the notes on environment sound."""
import sys,os,struct,json
sys.path.insert(0,os.path.dirname(os.path.abspath(__file__)))
import gms_world, pathfind, gms_scripts
G=sys.argv[1]; S=sys.argv[2]
sc=gms_world.load_scene(G); b=sc.body
snd=open(S,'rb').read()
TYPES=['3D','2D_Culled','2D','2D_Pure','MUSIC','AMBIENT','CENTER','FRONT','SUB_WOFFER','3D_PAN']
def cstr(o):
    e=snd.find(b'\0',o); return snd[o:e].decode('latin-1')
def sndrec(o):
    t=struct.unpack_from('<I',snd,o)[0]
    if t==2:
        _,n,w,a,bb,c=struct.unpack_from('<IIIffI',snd,o)
        _,fp,whd,dur=struct.unpack_from('<IIIf',snd,w)
        return dict(kind='single',name=cstr(n),file=cstr(fp),whdIndex=((whd&~1)-0x10)//48,streamed=not (whd&1),dur=round(dur,3),a=a,b=bb,c=c)
    if t==3:
        _,n,cnt,mode,x,lp,y=struct.unpack_from('<IIHHIII',snd,o)
        items=[sndrec(struct.unpack_from('<I',snd,lp+4*i)[0]) for i in range(cnt)]
        return dict(kind='list',name=cstr(n),mode=mode,x=x,y=y,items=items)
    return dict(kind='type%d'%t)
def R(v):
    k=gms_scripts.ref_index(v); return None if k is None else k+1
out=[]
for g in sc.geoms:
    if g['cls']!=0x200012: continue
    rec=g['rec']; evs=gms_scripts.event_names(b,rec)
    off=gms_scripts.u32(b,rec+0x20)
    its=pathfind.parse_dblk(b,off)['items'] if off else []
    blocks=[[]]
    for it in its:
        if it['type']==6: blocks.append([])
        elif it['type']!=0xff: blocks[-1].append(it)
    own=[it.get('value',it.get('refs')) for it in blocks[0]]
    names=['Type','Sound','InnerConeAngle','OuterConeAngle','OuterConeVolume','LPCutOffFreq','AutoAttach','Loop','Volume','mindist','SourceGroup','Delete','AutoFadeTime']
    o=dict(zip(names,own))
    o['Type']=TYPES[o['Type']] if isinstance(o.get('Type'),int) and o['Type']<10 else o.get('Type')
    e={}
    for k,ev in enumerate(evs):
        blk=blocks[k+1] if k+1<len(blocks) else []
        e[ev.replace('ZSNDOBJ_','')]=[ [R(x) for x in it['refs']] if it['type']==9 else it.get('value') for it in blk]
    so=gms_scripts.u32(b,rec+0x28)
    scr=None
    if so:
        d=pathfind.parse_dblk(b,so)['items']; scr=d[0]['value']
    out.append(dict(ref=g['index']+1,path=sc.path(g['index']),pos=[round(x,1) for x in g['wp']],room=(sc.room_of(g['index']) or -1)+1,
        own=o,sound=sndrec(o['Sound']) if o.get('Sound') else None,events=e,script=scr))
json.dump(out,open(sys.argv[3],'w'),indent=1)
from collections import Counter
print(len(out)); print(Counter(tuple(sorted(x['events'])) for x in out).most_common())
print(Counter(x['own']['Type'] for x in out)); print('loop',Counter(x['own']['Loop'] for x in out))
