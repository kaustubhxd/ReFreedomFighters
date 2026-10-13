"""specs_f16b019.py - fresh slice 16 batch 19 (see src/f16b019.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr


def _cstr(c, b):
    a = c.emu.alloc(len(b) + 1, 4)
    c.emu.wbytes(a, b + b'\0')
    return a


def _rstr(c):
    r = c.rng
    return bytes(r.choice(b'abcXYZ_09') for _ in range(r.randrange(0, 24)))


def _436(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    s = _cstr(c, _rstr(c)) if r.random() < 0.8 else 0
    phook(c, seq, 0x4cc1d0, 0, this=True, ret=s)
    phook(c, seq, 0x41e290, 1, ret=rnd(c, 0x30))
    phook(c, seq, 0x439c20, 1, this=True, pop=True)
    return [rnd(c, 0x20), r.choice([0, r.getrandbits(32)]), rnd(c, 0xb0)]


def _cut(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = codeaddr(c)
    phook(c, seq, h, 0)
    c.emu.w32(0x7003b0, h)
    db = obj(c, 0x80, {0x34: stub(c, seq, 1)})
    sysobj(c, db=db)
    phook(c, seq, 0x4690b0, 2)
    return [rnd(c, 0x50), r.choice([0, 1, 4, 5, 3, 7, r.getrandbits(32)])]


def _5fa(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    h = codeaddr(c)
    phook(c, seq, h, 0)
    c.emu.w32(0x7003b0, h)
    k = r.random()
    if k < 0.3:
        nm = bytes(c.emu.rbytes(0x6b91c8, 40)).split(b'\0')[0]
    elif k < 0.6:
        nm = bytes(c.emu.rbytes(0x694c6c, 40)).split(b'\0')[0]
    else:
        nm = _rstr(c)
    if r.random() < 0.5:
        nm = bytes(ch ^ 0x20 if 65 <= (ch | 0x20) - 32 + 32 and (ch | 0x20) in range(97, 123) and r.random() < 0.5 else ch for ch in nm)
    name = _cstr(c, nm)

    def icmp(e, _):
        a, b = e.arg32(0), e.arg32(1)
        sa = bytes(e.rbytes(a, 64)).split(b'\0')[0].lower()
        sb = bytes(e.rbytes(b, 64)).split(b'\0')[0].lower()
        e.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff))
    c.emu.stub_import('_stricmp', icmp)
    phook(c, seq, 0x602d30, 0, ret=rnd(c, 0x10))
    t = 0
    if r.random() < 0.4:
        t = rnd(c, 0x20)
        c.emu.w32(t + 0x1c, obj(c, 0x20, {0x14: stub(c, seq, 3, ret=r.getrandbits(32))}))
    phook(c, seq, 0x602ff0, 1, this=True, pop=True, ret=t)
    lib = obj(c, 0x60, {0x40: stub(c, seq, 2, ret=r.getrandbits(32)), 0x44: stub(c, seq, 2, ret=r.getrandbits(32))})
    phook(c, seq, 0x5fa630, 0, ret=lib)
    return [rnd(c, 0x10), name, rnd(c, 0x10)]


S(0x436a80, 'FUN_436a80 (named entry ctor)', 'thiscall', None, ret='eax', gen=_436, note='f16b019')
S(0x4b1000, 'CCutSequenceSoundFXAttenuation scalar deleting dtor', 'thiscall', None, ret='eax', gen=_cut, note='f16b019; SEH not reproduced')
S(0x4b2180, 'CTimeOutDelete scalar deleting dtor', 'thiscall', None, ret='eax', gen=_cut, note='f16b019; SEH not reproduced')
S(0x5fa380, 'OpaqueObjectSerialBuffer_t::produceOpaqueFromSerial', 'thiscall', None, ret='eax', gen=_5fa, note='f16b019; _stricmp stubbed')
