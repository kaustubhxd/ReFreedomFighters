"""Freedom Fighters .ppo script bytecode disassembler (opcode table: opcodes.md).
Usage: python3 -I ppo_dis.py a.ppo [b.ppo ...]   -> checks each decodes cleanly
       python3 -I ppo_dis.py -l child.ppo [parent.ppo ...] -> raw listing with strings resolved
For labelled listings (states, parents found automatically) use ppo_list.py."""
import struct,sys
# operand codes: B u8, H u16, V u16 var-ref, S u16 string id, F u16 function idx, h i16,
# I u32, i i32, f f32, T u32 code target (absolute code offset), z inline C string,
# '*' marks variable-length switch tables (handled specially)
OPS = {
 0x00:('NOP',''),
 0x01:('INC_I','V'), 0x02:('DEC_I','V'),
 0x03:('LNOT',''), 0x04:('LAND_I',''), 0x05:('LOR_I',''), 0x06:('LOR_F',''), 0x07:('LAND_F',''),
 0x08:('BNOT',''), 0x09:('BAND',''), 0x0a:('BOR',''), 0x0b:('NEG_I',''), 0x0c:('NEG_F',''),
 0x0d:('FNOT',''), 0x0e:('ADD_F',''), 0x0f:('ADD_I',''), 0x10:('SUB_F',''), 0x11:('SUB_I',''),
 0x12:('MUL_F',''), 0x13:('MUL_I',''), 0x14:('DIV_F',''), 0x15:('DIV_I',''),
 0x16:('ADDV_F_IMM','Vf'), 0x17:('ADDV_I_IMM','Vi'), 0x18:('SUBV_F_IMM','Vf'), 0x19:('SUBV_I_IMM','Vi'),
 0x1a:('MULV_F_IMM','Vf'), 0x1b:('MULV_I_IMM','Vi'), 0x1c:('DIVV_F_IMM','Vf'), 0x1d:('DIVV_I_IMM','Vi'),
 0x1e:('ADDX_I_IMM','i'), 0x1f:('ADDX_F_IMM','f'), 0x20:('SUBX_I_IMM','i'), 0x21:('SUBX_F_IMM','f'),
 0x22:('MULX_I_IMM','i'), 0x23:('MULX_F_IMM','f'), 0x24:('DIVX_I_IMM','i'), 0x25:('DIVX_F_IMM','f'),
 0x26:('MAX_F',''), 0x27:('MIN_F',''), 0x28:('MAXV_F_IMM','Vf'), 0x29:('MINV_F_IMM','Vf'),
 0x2a:('PUSH_F','f'), 0x2b:('PUSH_I','i'), 0x2c:('LOADX_I',''), 0x2d:('LOADX_F',''),
 0x2e:('LOAD_F','V'), 0x2f:('LOAD_I','V'), 0x30:('LOAD_F2I','V'), 0x31:('LOAD_I2F','V'),
 0x32:('STORE_F','V'), 0x33:('STORE_I','V'), 0x34:('STORE_F2I','V'), 0x35:('STORE_I2F','V'),
 0x36:('ADDV_F','V'), 0x37:('ADDV_I','V'), 0x38:('SUBV_F','V'), 0x39:('SUBV_I','V'),
 0x3a:('MULV_F','V'), 0x3b:('MULV_I','V'), 0x3c:('DIVV_F','V'), 0x3d:('DIVV_I','V'),
 0x3e:('MINV_F','V'), 0x3f:('MAXV_F','V'),
 0x40:('ADDX_I',''), 0x41:('ADDX_F',''), 0x42:('SUBX_I',''), 0x43:('SUBX_F',''),
 0x44:('MULX_I',''), 0x45:('MULX_F',''), 0x46:('DIVX_I',''), 0x47:('DIVX_F',''),
 0x48:('MINX_F',''), 0x49:('MAXX_F',''),
 0x4a:('CALL','F'), 0x4b:('RET',''), 0x4c:('POPN','I'), 0x4d:('JMP','T'),
 0x4e:('JNZ','TI'), 0x4f:('JZ','TI'), 0x50:('JZ_YIELD','T'),
 0x51:('SETSTATE','I'), 0x52:('SETSTATE_V','I'), 0x53:('SETSTATE_FN','F'),
 0x54:('LT_I',''), 0x55:('GT_I',''), 0x56:('LE_I',''), 0x57:('GE_I',''), 0x58:('EQ_I',''), 0x59:('NE_I',''),
 0x5a:('LT_F',''), 0x5b:('GT_F',''), 0x5c:('LE_F',''), 0x5d:('GE_F',''), 0x5e:('EQ_F',''), 0x5f:('NE_F',''),
 0x60:('STOREX_I_IMM','i'), 0x61:('STOREX_F_IMM','f'), 0x62:('STOREX_I',''), 0x63:('STOREX_F',''),
 0x64:('SETV_F','Vf'), 0x65:('SETV_I','Vi'), 0x66:('MOVV_F','VV'), 0x67:('MOVV_I','VV'),
 0x68:('BREAK',''), 0x69:('I2F','I'), 0x6a:('SWAP',''),
 0x6b:('SWITCH_I','*'), 0x6c:('SWITCH_FRANGE','*'),
 0x6d:('SLEEP',''), 0x6e:('SLEEP_IMM','If'), 0x6f:('WAITFOREVENT',''), 0x70:('WAITFORNAMEDEVENT','z'),
 0x71:('ATOMIC_N','I'), 0x72:('JMP_SETSV','Ti'), 0x73:('SETSTARTSTATE','I'),
 0x74:('JSV1','T'), 0x75:('JNSV1','T'), 0x76:('CALLA','T'), 0x77:('CTOR_END',''),
 0x78:('HANDLER_JMP','Ii'), 0x79:('HANDLER_JMP_FN','Fi'), 0x7a:('TERMINATE',''), 0x7b:('YIELD',''),
 0x7c:('OP7C','I'), 0x7d:('ARRAY_REF','III'), 0x7e:('PUSH_STATE',''),
 0x7f:('STORE_O','V'), 0x80:('STOREX_O',''), 0x81:('LOAD_O','V'), 0x82:('NEWDEFAULT','z'),
 0x85:('CAST','z'), 0x87:('LOAD_I2','V'), 0x86:('SAT_F',''),
 0x88:('ADDVV_I','VV'), 0x89:('SUBVV_I','VV'), 0x8a:('MULVV_I','VV'), 0x8b:('DIVVV_I','VV'),
 0x8c:('ADDVV_F','VV'), 0x8d:('SUBVV_F','VV'), 0x8e:('MULVV_F','VV'), 0x8f:('DIVVV_F','VV'),
 0x90:('FRAME','i'), 0x91:('DUMPSTATE',''), 0x92:('SET_QUOTA',''), 0x93:('SET_BUDGET','I'),
 0x94:('PUSH_I2','i'), 0x95:('CALL_NATIVE','SSHI'), 0x96:('CALL_METHOD','VSHI'), 0x97:('PUSH_STR','S'),
 0x98:('LOADX_O',''), 0x99:('PUSH_OBJ_82',''), 0x9a:('PUSH_OBJ_1A',''), 0x9b:('EVLOCK',''), 0x9c:('EVUNLOCK',''),
 0x9d:('NOP2',''), 0x9e:('YIELD2',''),
}
SZ={'B':1,'H':2,'V':2,'S':2,'F':2,'h':2,'I':4,'i':4,'f':4,'T':4}
def var(v):
  if v<0x8000: return 'd[%#x]'%v
  if v&0x4000: s=v-0x10000; return 'fp[%d]'%s
  return 'g[%d]'%((~(v|0x4000))&0xffff)
def dec(code, base=0):
  pc=0; out=[]
  while pc<len(code):
    op=code[pc]
    if op not in OPS: out.append((pc,None,'UNKNOWN %#x'%op)); return out,pc,False
    m,fmt=OPS[op]; p=pc+1; args=[]
    if fmt=='*':
      n,dflt=struct.unpack_from('<Ii',code,p); p+=8
      ents=[]
      for k in range(n):
        if op==0x6b: v,t=struct.unpack_from('<iI',code,p)
        else: v,t=struct.unpack_from('<fI',code,p)
        ents.append('%s->%#x'%(v,t)); p+=8
      args=['n=%d'%n,'def=%#x'%(dflt&0xffffffff)]+ents
      if dflt!=-1: args.append('pad=%s'%code[p:p+8].hex()); p+=8  # compiler emits 8 dead bytes after table when a default exists
    else:
      for c in fmt:
        if c=='z':
          e=code.index(b'\0',p); args.append(repr(code[p:e].decode('latin-1'))); p=e+1; continue
        if c in 'VSFH': v=struct.unpack_from('<H',code,p)[0]
        elif c=='h': v=struct.unpack_from('<h',code,p)[0]
        elif c in 'IT': v=struct.unpack_from('<I',code,p)[0]
        elif c=='i': v=struct.unpack_from('<i',code,p)[0]
        elif c=='f': v=struct.unpack_from('<f',code,p)[0]
        elif c=='B': v=code[p]
        p+=SZ[c]
        args.append(var(v) if c=='V' else ('str#%d'%v if c=='S' else ('fn#%d'%v if c=='F' else ('@%#x'%v if c=='T' else (('%g'%v) if c=='f' else ('%#x'%v if c in 'IH' else str(v)))))))
    if p>len(code): out.append((pc,m,'TRUNCATED')); return out,pc,False
    out.append((pc,m,', '.join(args),code[pc:p].hex(' '))); pc=p
  return out,pc,pc==len(code)
def code_of(path):
  d=open(path,'rb').read()
  for k in range(4,len(d)-200):
    if d[k:k+4]!=b'\x00\x00\x80\x3f': continue
    o=k-4
    try:
      hdr=struct.unpack_from('<I f I I 4H 16s 16s 6I 12I',d,o)
    except Exception: continue
    size=hdr[-1]; o90=hdr[-2]; blob=o+4*4+8+32+24+48
    if size>0 and blob+size<=len(d):
      b=d[blob:blob+size]; n=struct.unpack_from('<I',b,o90)[0]
      return b[o90+4:o90+4+n], o90
  return None,None
if __name__=="__main__" and sys.argv[1]!="-l":
  for f in sys.argv[1:]:
    code,o90=code_of(f)
    out,pc,ok=dec(code)
    print('==',f,'codelen',len(code),'consumed',pc,'clean' if ok else 'FAIL',out[-1] if not ok else '')

def load(path):
  """returns dict with code, base (code offset of first byte), strings{id:str}"""
  d=open(path,'rb').read()
  for k in range(4,len(d)-200):
    if d[k:k+4]!=b'\x00\x00\x80\x3f': continue
    o=k-4
    try: hdr=struct.unpack_from('<I f I I 4H 16s 16s 6I 12I',d,o)
    except Exception: continue
    size=hdr[-1]; blob=o+4*4+8+32+24+48
    if not(size>0 and blob+size<=len(d)): continue
    b=d[blob:blob+size]; h38=hdr[10:16]; tabs=hdr[16:28]
    o7c=tabs[5]; o90=tabs[10]
    n=struct.unpack_from('<I',b,o90)[0]; code=b[o90+4:o90+4+n]
    first,cnt=struct.unpack_from('<II',b,o7c)
    offs=struct.unpack_from('<%dI'%cnt,b,o7c+8); sb=o7c+8+4*cnt
    strs={first+i: b[sb+x:b.index(b'\0',sb+x)].decode('latin-1') for i,x in enumerate(offs)}
    return dict(code=code,base=h38[0],strings=strs,blob=b)

def listing(path, parents=(), limit=None):
  P=load(path); S={}
  for pp in parents: S.update(load(pp)['strings'])
  S.update(P['strings'])
  out,pc,ok=dec(P['code'])
  import re
  lines=[]
  for r in out[:limit]:
    a=re.sub(r'str#(\d+)', lambda m: 'str#%s"%s"'%(m.group(1),S.get(int(m.group(1)),'?')), r[2])
    lines.append('%05x  %-28s %-14s %s'%(P['base']+r[0], r[3][:28], r[1], a))
  return lines, pc, len(P['code']), ok
if __name__=='__main__' and len(sys.argv)>2 and sys.argv[1]=='-l':
  L,pc,n,ok=listing(sys.argv[2], sys.argv[3:])
  print('\n'.join(L)); print('consumed %d/%d %s'%(pc,n,'clean' if ok else 'FAIL'))
