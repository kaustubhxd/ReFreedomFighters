"""specs_s38088.py - cascade s8 batch 38088. thiscall(stream) ret 4. this = 0x100-byte random block with an id table (+0x44 -> 8-byte entries, count +0x4c 0..4), +0x14 / +0x18 -> small blocks whose +0xc dword (up to ~5000, so the bit-mask byte
count and its trimmed last byte vary) is written to the stream. The stream's slots 8 (tag), 0xc (dword) and 0x10 (bytes) are logging stubs (the bytes written are logged by content); the engine system object has slot 8 and a
table +0x10 field. 0x41e290 (new) returns a heap buffer, 0x634d10 (memset) really fills it and logs, 0x634273 (free) logs; 0x498e60 / 0x496380 / 0x498cc0 (logs the dword its pointer argument refers to) / 0x498be0 / 0x4991c0 are hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _g4989a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def tagf(em, res_):
        em.calllog.append(('tag', em.arg32(0)))
        em.ret(eax=0, argbytes=4)

    def dw(em, res_):
        em.calllog.append(('dword', em.arg32(0)))
        em.ret(eax=0, argbytes=4)

    def by(em, res_):
        p, n = em.arg32(0), em.arg32(1)
        em.calllog.append(('bytes', n, bytes(em.rbytes(p, n))))
        em.ret(eax=0, argbytes=8)
    st = obj(c, 0x40, {8: e.stub_fn('tag', tagf), 0xc: e.stub_fn('dword', dw), 0x10: e.stub_fn('bytes', by)})
    sysobj(c, slots={8: e.stub_fn('systag', lambda em, res_: (em.calllog.append(('systag', em.arg32(0))), em.ret(eax=0, argbytes=4)))}, table_size=0x40)

    def new(em, res_):
        n = em.arg32(0)
        em.calllog.append(('new', n))
        em.ret(eax=e.alloc(max(n, 16), 4), argbytes=0)
    e.hook(0x41e290, new)

    def ms(em, res_):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', v, n))
        em.wbytes(p, bytes([v & 0xff]) * n)
        em.ret(eax=p, argbytes=0)
    e.hook(0x634d10, ms)
    e.hook(0x634273, lambda em, res_: (em.calllog.append(('free', em.arg32(1), bytes(em.rbytes(em.arg32(0), 4)))), em.ret(eax=0, argbytes=0)))
    hook_rec(c, 0x498e60, 1, this=True, pop=4)
    hook_rec(c, 0x4991c0, 1, this=True, pop=4)

    def mask_hook(addr, name):
        def h(em, res_):
            p = em.arg32(0)
            em.calllog.append((name, em.reg('ecx') != 0, em.r32(p)))
            em.ret(eax=0, argbytes=4)
        e.hook(addr, h)
    mask_hook(0x498cc0, '498cc0')
    mask_hook(0x498be0, '498be0')

    def a496380(em, res_):
        p = em.arg32(0)
        em.calllog.append(('496380', em.reg('ecx') != 0, bytes(em.rbytes(p, 8))))
        em.ret(eax=0, argbytes=4)
    e.hook(0x496380, a496380)
    this = rnd(c, 0x100)
    n = r.choice([0, 1, 2, 4])
    ids = rnd(c, 64)
    e.w32(this + 0x44, ids)
    e.w32(this + 0x4c, n)
    for k in (0x14, 0x18):
        blk = rnd(c, 0x20)
        e.w32(blk + 0xc, r.choice([0, 7, 111, 112, 113, 500, 800, 896, 1000, 2000, r.randrange(0, 5000)]))
        e.w32(this + k, blk)
    return [this, st]


S(0x4989a0, 'GUESS serialize object to stream', 'thiscall', None, ret=None, gen=_g4989a0, note='batch38088')
