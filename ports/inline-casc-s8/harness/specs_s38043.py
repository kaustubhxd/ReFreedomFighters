"""specs_s38043.py - cascade s8 batch 38043. The object (null 8%) has recording slots 0x1e0 (flag test), 0x328 / 0x364 / 0x35c (random values, 0x328 / 0x364 sometimes zero), 0x2e8 (returns a name record whose +4 is
either 0, or one of the four compared strings from the image / an unrelated string, random case); _stricmp (IAT 0x676414) is a logged Python stub. The partner list (this+0x1d0b) has slot 0x55c (returns a partner
or 0) whose slot 0x320 returns a number; the engine text object (slot 0x190 -> object with the sprintf-like slot 0x198) writes a deterministic string into the stack buffer and logs its arguments; 0x5afef0 returns
0..4; the caption list (this+0x1d0f, null 15%) gets 0x5aa020 (hook) or 0x5aa060, a custom stub that logs the C string it is given."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

STRS = [0x6ad8b4, 0x6b0090, 0x690aec, 0x690af4]


def _cstr(em, p):
    out = b''
    while len(out) < 80:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g5b0010(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def h(em, res_):
        a, b = em.arg32(0), em.arg32(1)
        sa, sb = _cstr(em, a).lower(), _cstr(em, b).lower()
        em.calllog.append(('_stricmp', 0, 0, (sa, sb)))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676414, e.stub_fn('_stricmp', h))

    def fmt(em, res_):
        buf, f = em.arg32(1), em.arg32(2)
        vals = tuple(em.arg32(3 + i) for i in range(2 if f == 0x6b113c else 1))
        em.calllog.append(('fmt', em.reg('ecx') != 0, f, vals))
        em.wbytes(buf, (':'.join('%x' % v for v in vals)).encode()[:0x1e] + b'\0')
        em.ret(eax=0, argbytes=0)
    a_obj = obj(c, 0x20, {0x198: e.stub_fn('fmt', fmt)})
    so = sysobj(c, {0x190: pystub(c, 0, this=True, ret=a_obj)})
    nm_ptr = 0
    k = r.random()
    if k < 0.2:
        nm_ptr = 0
    elif k < 0.8:
        s = _cstr(e, r.choice(STRS))
        s = bytes(ch ^ 0x20 if (65 <= (ch | 0x20) <= 90 and r.random() < 0.5) else ch for ch in s)
        nm_ptr = e.alloc(len(s) + 1, 1)
        e.wbytes(nm_ptr, s + b'\0')
    else:
        nm_ptr = e.alloc(8, 1)
        e.wbytes(nm_ptr, b'zzz\0')
    rec = rnd(c, 0x10)
    e.w32(rec + 4, nm_ptr)
    pf = r.choice([0.3, 0.8])
    o = obj(c, 0x400, {0x1e0: pystub(c, 1, this=True, ret=lambda em, kk: r.choice([1, 1, 0x100, 0])),
                       0x328: pystub(c, 0, this=True, ret=lambda em, kk: r.choice([0, 5, r.getrandbits(32)])),
                       0x364: pystub(c, 0, this=True, ret=lambda em, kk: r.choice([0, 1, r.getrandbits(32)])),
                       0x35c: pystub(c, 0, this=True, ret=lambda em, kk: r.getrandbits(32) & 0xffff),
                       0x2e8: pystub(c, 0, this=True, ret=rec)})
    partner = obj(c, 0x40, {0x320: pystub(c, 0, this=True, ret=lambda em, kk: r.getrandbits(32) & 0xff)})
    lst = obj(c, 0x40, {0x55c: pystub(c, 1, this=True, ret=lambda em, kk: partner if r.random() < pf else 0)})

    def s5aa060(em, res_):
        em.calllog.append(('caption', em.reg('ecx'), _cstr(em, em.arg32(0))))
        em.ret(eax=0, argbytes=4)
    cap = e.stub_fn('s5aa060', s5aa060)
    me = rnd(c, 0x1e00)
    e.w32(me + 0x1d0b, lst)
    e.wbytes(me + 0x1d0f, struct.pack('<I', 0 if r.random() < 0.15 else rnd(c, 0x20)))
    hook_rec(c, 0x5afef0, 1, this=True, pop=4, ret=lambda em, kk: r.choice([0, 1, 2, 5, 0x41]))
    hook_rec(c, 0x5aa020, 1, this=True, pop=4)
    e.hook(0x5aa060, s5aa060)
    return [me, 0 if r.random() < 0.08 else o]


S(0x5b0010, 'GUESS HUD caption for object', 'thiscall', None, ret=None, gen=_g5b0010, note='batch38043')
