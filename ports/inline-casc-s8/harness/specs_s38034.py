"""specs_s38034.py - cascade s8 batch 38034. The name argument is one of the sixteen table strings read from the image (random case), null (8%), or an unknown string; it equals the stored this+0x685 value
about 10% of the time. _stricmp (IAT 0x676414) is a logged Python stub with the CRT's ASCII case folding; 0x5a8360 returns an entry object (80%) or 0 (hooked, key recorded); 0x5ebd80 is a recording
hook; the logger stream (slot 0x30, 3 args) and the unaligned this+0x685 / this[0x430] fields are set up."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

STRS = [0x6ad858, 0x690aec, 0x6ad894, 0x6ad870, 0x6ad8b4, 0x6ad8a8, 0x6b0090, 0x690af4, 0x6b00a8, 0x6ad838, 0x6ad84c, 0x6ad884, 0x6b00b4, 0x6ac9a0, 0x6ad8a0, 0x6acb04]


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g5a9e20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def h(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', 0, 0, (sa, sb)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', h))
    st = obj(c, 0x20, {0x30: pystub(c, 3, pop=0)})

    def lg(em, res_):
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), em.arg32(1)))
        em.ret(eax=st, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    k = r.random()
    if k < 0.08:
        name = 0
    elif k < 0.85:
        s = _cstr(e, r.choice(STRS))
        s = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.5) else ch for ch in s)
        name = e.alloc(len(s) + 1, 1)
        e.wbytes(name, s + b'\0')
    else:
        s = r.choice([b'nothing', b'', b'zzz'])
        name = e.alloc(len(s) + 1, 1)
        e.wbytes(name, s + b'\0')
    me = rnd(c, 0x700)
    e.wbytes(me + 0x685, struct.pack('<I', name if r.random() < 0.1 else r.getrandbits(32)))
    e.w32(me + 0x430, rnd(c, 0x40))
    entry = rnd(c, 0x10)
    hook_rec(c, 0x5a8360, 1, this=True, pop=4, ret=lambda em, kk: entry if r.random() < 0.8 else 0)
    hook_rec(c, 0x5ebd80, 1, this=True, pop=4)
    return [me, name]


S(0x5a9e20, 'GUESS select entry by name', 'thiscall', None, ret=None, gen=_g5a9e20, note='batch38034')
