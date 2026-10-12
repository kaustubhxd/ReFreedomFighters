"""specs_s7373.py - area 73 batch 73 (gap band, GUESS names). Arities come from the call sites (no pushes = zero arguments).
FUN_4ee530 (ret 4, returns this): 0x4ee440(this) (hooked, 0 args); flag bit 0: bit 2 -> 0x4690b0(this, 0xac), else 0x45c510(this) (cdecl).
FUN_4f1ae0 (ret 4, returns this): 0x4f1a10(this) (hooked, 0 args); flag bit 0: bit 2 -> 0x4690b0(this, 0x63c), else 0x45c510(this).
FUN_4f4390 (ret 0xc, returns this): 0x4ee1b0(this, a, b, c) (hooked, three args); vtable 0x699664; [+0xac] = 0; [+0xb0] = 0.
FUN_4f4a30 (ret 0xc, returns this): 0x4f97f0(this, a, b, c) (hooked, three args); vtable 0x699924; [+0x8f] = 0; [+0x93] = 1."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook_common(c):
    e = c.emu

    def h0(addr, name):
        def h(em, r):
            em.calllog.append((name, 0, em.reg('ecx'), ()))
            em.ret(argbytes=0)
        return h

    def h3(addr, name):
        def h(em, r):
            em.calllog.append((name, 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
            em.ret(eax=0, argbytes=12)
        return h

    def hc(em, r):
        em.calllog.append(('45c510', 0, None, (em.arg32(0),)))
        em.ret(argbytes=0)

    def hd(em, r):
        em.calllog.append(('4690b0', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    e.hook(0x4ee440, h0(0x4ee440, '4ee440'))
    e.hook(0x4f1a10, h0(0x4f1a10, '4f1a10'))
    e.hook(0x4ee1b0, h3(0x4ee1b0, '4ee1b0'))
    e.hook(0x4f97f0, h3(0x4f97f0, '4f97f0'))
    e.hook(0x45c510, hc)
    e.hook(0x4690b0, hd)


def _gen_flag(c):
    _hook_common(c)
    return [_rnd(c, 0x100), c.rng.choice([0, 1, 5, c.rng.getrandbits(8)])]


def _gen_ctor(c):
    _hook_common(c)
    return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4ee530, 'GUESS FUN_4ee530 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_flag,
  note='area 73 batch 73; 0x4ee440(this); flag&1: flag&4 ? 0x4690b0(this,0xac) : 0x45c510(this); returns this')
S(0x4f1ae0, 'GUESS FUN_4f1ae0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_flag,
  note='area 73 batch 73; 0x4f1a10(this); flag&1: flag&4 ? 0x4690b0(this,0x63c) : 0x45c510(this); returns this')
S(0x4f4390, 'GUESS FUN_4f4390 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_ctor,
  note='area 73 batch 73; 0x4ee1b0(this,a,b,c); [this]=0x699664; [+0xac]=0; [+0xb0]=0; returns this')
S(0x4f4a30, 'GUESS FUN_4f4a30 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_ctor,
  note='area 73 batch 73; 0x4f97f0(this,a,b,c); [this]=0x699924; [+0x8f]=0; [+0x93]=1; returns this')
