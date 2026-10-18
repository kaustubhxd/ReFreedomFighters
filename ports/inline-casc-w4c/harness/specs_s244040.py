"""specs_s244040.py - hand-written specs for batch 244040."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain
import pe_emu


def g4274a0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu

    def cs(emu, p, n=0x200):
        out = b''
        while p and len(out) < n:
            ch = bytes(emu.rbytes(p + len(out), 1))
            if ch == b'\0':
                break
            out += ch
        return out

    def sehlog(emu):
        a = emu.r32(pe_emu.TEB)
        emu.calllog.append(('seh', emu.r32(a + 8) if a != 0xffffffff else -1, emu.r32(a + 4) if a != 0xffffffff else -1))
    # --- file image served by fread / fseek
    IMG = 0x1000
    img = bytearray(IMG)
    for i in range(0, IMG, 4):
        img[i:i + 4] = struct.pack('<I', r.choice([0, 1, 2, 3, 4, 5]) * 4 if r.random() < 0.9 else r.getrandbits(32) & 0xfff)
    P = r.choice([0x80, 0x100, 0x40, 0x200])
    img[0x3c:0x40] = struct.pack('<I', P)
    img[P:P + 4] = struct.pack('<I', 0x4550 if r.random() < 0.85 else r.getrandbits(32))
    img[P + 0x14:P + 0x16] = struct.pack('<H', r.choice([0xe0, 0x10, 0xf0]))
    img[P + 0x18 + 0x60:P + 0x18 + 0x64] = struct.pack('<I', r.choice([1, 0x2000, 0x1234]))   # export dir RVA (non-zero: zero would call the noreturn exit)
    for off in (P + 0x78 + 4, ):
        pass
    st = {'pos': 0}

    def fseek(emu, k):
        st['pos'] = emu.arg32(1) & 0x7fffffff
        emu.calllog.append(('fseek', emu.arg32(0), emu.arg32(1), emu.arg32(2)))
        sehlog(emu)

    def fread(emu, k):
        sz, cnt = emu.arg32(1), emu.arg32(2)
        n = min(sz * cnt, 8)
        pos = st['pos'] % (IMG - 8)
        emu.wbytes(emu.arg32(0), bytes(img[pos:pos + n]))
        st['pos'] += n
        emu.calllog.append(('fread', sz, cnt, emu.arg32(3), st['pos'] % (IMG - 8), bytes(img[pos:pos + n])))
        sehlog(emu)
    em.w32(0x6763e8, pystub(c, 3, ret=lambda emu, k: 0, pop=0, side=fseek))
    em.w32(0x6763f8, pystub(c, 4, ret=lambda emu, k: 1, pop=0, stackmark=(0,), side=fread))
    em.w32(0x6763b0, pystub(c, 2, ret=lambda emu, k: 0x7000 + r.randrange(1, 9), pop=0, stackmark=(0, 1), side=lambda emu, k: (emu.calllog.append(('fopen', cs(emu, emu.arg32(0)), cs(emu, emu.arg32(1)))), sehlog(emu))))
    em.w32(0x6763ac, pystub(c, 1, ret=lambda emu, k: 0, pop=0, side=lambda emu, k: (emu.calllog.append(('fclose', emu.arg32(0))), sehlog(emu))))
    em.w32(0x676374, pystub(c, 1, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('exit', emu.arg32(0)))))
    paths = [b'Glacier.dlc', b'C:\\game\\Glacier.dlc', b'plugin.dll', b'a\\b\\x.dll', b'nofile']
    path = r.choice(paths)

    def stricmp(emu, k):
        a = cs(emu, emu.arg32(0)); b = cs(emu, emu.arg32(1))
        emu.calllog.append(('cmp', a, b))
        sehlog(emu)
        st['cmp'] = 0 if a == b else 1
    em.w32(0x676414, pystub(c, 2, ret=lambda emu, k: st['cmp'], pop=0, stackmark=(0, 1), side=stricmp))

    def strrchr(emu, k):
        s_, ch = emu.arg32(0), emu.arg32(1) & 0xff
        b = cs(emu, s_)
        i = b.rfind(bytes([ch]))
        emu.calllog.append(('strrchr', b, ch))
        st['rch'] = 0 if i < 0 else s_ + i
    em.w32(0x676254, pystub(c, 2, ret=lambda emu, k: st['rch'], pop=0, stackmark=(0,), side=strrchr))
    modpath = r.choice([b'C:\\gm\\Glacier.exe', b'Glacier.exe', b'x\\y.exe'])

    def gmfn(emu, k):
        emu.calllog.append(('gmfn', emu.arg32(0), emu.arg32(2)))
        emu.wbytes(emu.arg32(1), modpath + b'\0')
    em.w32(0x67607c, pystub(c, 3, ret=lambda emu, k: len(modpath), pop=12, stackmark=(1,), side=gmfn))
    # --- string class helpers (stack objects): hooks only log
    names = [b'X_ClassInfo@8', b'X_ClassInfo@8', b'abc@_ExpFunc', b'Foo_ClassInfo', b'Foo_ClassInfo@8', b'LongName_ClassInfo@12', b'LongName_ClassInfo@', b'foo@_ClassInfo', b'bar@xyz', b'_ExpFunc', b'Q_ExpFunc', b'Zlong_ExpFunc', b'Q_ExpFunc@12', b'zz_ClassInfo', b'x', b'k@_ExpFunc2', b'?m_ExpFunc', b'?_ExpFunc', b'ab_ExpFunx', b'abcdefgh_ExpFund', b'Aa_ClassInfx@9']
    pc = em.alloc(0x400, 4)
    em.wbytes(pc, path + b'\0')
    hook_rec(c, 0x4cbeb0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('s_ctor0',)), sehlog(emu)))
    hook_rec(c, 0x4cbe80, 1, ret=0, pop=4, this='mark', stackmark=(0,), side=lambda emu, k: (emu.calllog.append(('s_ctor', cs(emu, emu.arg32(0)))), sehlog(emu)))
    hook_rec(c, 0x4cbee0, 1, ret=0, pop=4, this='mark', stackmark=(0,), side=lambda emu, k: (emu.calllog.append(('s_assign',)), sehlog(emu)))
    hook_rec(c, 0x4cbec0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('s_dtor',)), sehlog(emu)))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: pc, pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('s_cstr',)), sehlog(emu)))
    hook_rec(c, 0x4cc1e0, 2, ret=lambda emu, k: emu.arg32(0), pop=8, this='mark', stackmark=(0, 1), side=lambda emu, k: (emu.calllog.append(('s_cat',)), sehlog(emu)))

    def fscanf(emu, k):
        nm = r.choice(names)
        emu.wbytes(emu.arg32(2), nm + b'\0')
        emu.calllog.append(('fscanf', emu.arg32(0), cs(emu, emu.arg32(1)), nm))
        sehlog(emu)
    hook_rec(c, 0x42aba4, 3, ret=r.getrandbits(32), pop=0, stackmark=(2,), side=fscanf)
    # --- objects
    def s138(emu, k):
        a, b_, c_ = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('t138', a, b_, c_))
        st['r138'] = ((b_ * 7 + c_ * 13) & 0x3fc) + 0x100
    me = obj(c, 0x40, {0x138: pystub(c, 3, ret=lambda emu, k: st['r138'], pop=12, this=True, side=s138)})
    G = rnd(c, 0x2000)
    em.w32(0x70039c, G)
    ao = obj(c, 0x40, {0x20: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=lambda emu, k: emu.calllog.append(('a1_20', cs(emu, emu.arg32(0)))))})
    bo = 0 if r.random() < 0.3 else obj(c, 0x40, {0x20: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=lambda emu, k: emu.calllog.append(('a2_20', cs(emu, emu.arg32(0)))))})
    pa = em.alloc(0x40, 4)
    em.wbytes(pa, path + b'\0')
    return [me, pa, ao, bo]


S(0x4274a0, 'GUESS plugin DLL export scanner: reads the PE export table of Glacier.dlc and registers *_ExpFunc / _ClassInfo names', 'thiscall', 3, ret=None, gen=g4274a0, note='batch244040')
