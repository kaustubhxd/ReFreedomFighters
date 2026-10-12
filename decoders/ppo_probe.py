import struct,sys,glob,os
def parse(d,o):
  r={}
  def u32():
    nonlocal o; v=struct.unpack_from('<I',d,o)[0]; o+=4; return v
  def u16():
    nonlocal o; v=struct.unpack_from('<H',d,o)[0]; o+=2; return v
  r['A']=u32(); r['ver']=struct.unpack_from('<f',d,o)[0]; o+=4
  r['h8']=u32(); r['hC']=u32(); r['u16']=[u16() for _ in range(4)]
  r['g1']=d[o:o+16].hex(); o+=16; r['g2']=d[o:o+16].hex(); o+=16
  r['h38']=[u32() for _ in range(6)]
  names=['o68','o6c','o70','o74','o78','o7c','o80','o84','o88','o8c','o90','size']
  for n in names: r[n]=u32()
  r['blob_at']=o; r['blob_end']=o+r['size']; o+=r['size']
  r['n12e']=u32() if o+4<=len(d) else None; r['n12a']=u32() if o+4<=len(d) else None
  r['after']=o; r['len']=len(d)
  return r
for f in sys.argv[1:]:
  d=open(f,'rb').read()
  i=d.find(struct.pack('<f',1.0))
  # find header: version float preceded by A; choose first occurrence after var table
  cands=[k for k in range(4,len(d)-200) if d[k:k+4]==b'\x00\x00\x80\x3f']
  for k in cands:
    try:
      r=parse(d,k-4)
      if r['blob_end']<=len(d) and r['size']>0: print(os.path.basename(f),hex(k-4),r); break
    except Exception as e: pass
