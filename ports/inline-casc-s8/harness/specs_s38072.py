"""specs_s38072.py - cascade s8 batch 38072. thiscall(a) void, this = 0xd00-byte entry panel: record table this[0xcea] (unaligned, sometimes 0 -> early exit), numbers this[0xce6] (sometimes 0) / [0xce2], settings [0xcae]/[0xcd2]/[0xcce],
four label objects (+0xcc2 / 0xcbe / 0xcb6 / 0xcba, slot 0x284 logs the text it gets). Engine system object: slot 0x190 -> formatter (slot 0x198 = cdecl varargs, logs and writes a text into the buffer), table +0xae4 -> text object
(slot 0 pops two args and returns one of three heap strings; for the two names that take the copied tag it logs the tag text). The record parser context (a stack buffer) is filled by the 0x5ad790 hook (kind at +0x3ba in 0..4, a value at +0x3c8,
two strings at +0x362 / +0x3a2 of at most 7 characters: the original copies the second one into an 8-byte buffer); 0x5ae450 / 0x5ae900 / 0x5adeb0 / 0x563710 / 0x5618b0 / 0x56c780 are hooked (0x5adeb0 logs the dword the port stored at ctx+0x86)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _cstr(em, p, lim=0x200):
    out = b''
    while len(out) < lim:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g56b460(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    strs = []
    for s in (b'alpha one', b'Beta', b'gamma three four'):
        p = e.alloc(0x20, 1)
        e.wbytes(p, s + b'\0')
        strs.append(p)

    def tx(em, res_):
        a0, a1 = em.arg32(0), em.arg32(1)
        em.calllog.append(('text', a0, _cstr(em, a1) if a0 in (0x6a7ba8, 0x6a7bc8) else a1))
        em.ret(eax=strs[(a0 + (a1 if a0 not in (0x6a7ba8, 0x6a7bc8) else len(_cstr(em, a1)))) % 3], argbytes=8)

    def fm(em, res_):
        a2 = em.arg32(2)
        row = ['fmt', em.arg32(0) != 0, a2, em.arg32(3)]
        if a2 != 0x69d384:
            row.append(em.arg32(4))
        em.calllog.append(tuple(row))
        em.wbytes(em.arg32(1), b'T' + ('%x.%x' % (a2 & 0xffff, em.arg32(3) & 0xffff)).encode() + b'\0')
        em.ret(eax=0, argbytes=0)
    F = obj(c, 0x20, {0x198: e.stub_fn('fmt', fm)})
    tb2 = obj(c, 0x20, {0x00: e.stub_fn('text', tx)})
    so = sysobj(c, slots={0x190: e.stub_fn('s190', lambda em, res_: (em.calllog.append(('s190',)), em.ret(eax=F)))}, table_size=0xb00)
    e.w32(e.r32(so + 0x9b) + 0xae4, tb2)

    def mklab(name):
        def lab(em, res_):
            em.calllog.append((name, _cstr(em, em.arg32(0))))
            em.ret(eax=0, argbytes=4)
        return obj(c, 0x20, {0x284: e.stub_fn(name, lab)})
    this = rnd(c, 0xd00)
    tbl = rnd(c, 0x2200)
    for off, v in ((0xcea, tbl if r.random() > 0.08 else 0), (0xce6, r.choice([0, 3, 7, r.getrandbits(32)]) if r.random() < 0.1 else r.randrange(1, 99)),
                   (0xce2, r.randrange(0, 20)), (0xcae, r.getrandbits(32)), (0xcd2, r.getrandbits(32)), (0xcce, r.choice([0, 1, 1])),
                   (0xcc2, mklab('lab-cc2')), (0xcbe, mklab('lab-cbe')), (0xcb6, mklab('lab-cb6')), (0xcba, mklab('lab-cba'))):
        e.wbytes(this + off, struct.pack('<I', v))

    def ctor(em, res_):
        cx = em.reg('ecx')
        em.wbytes(cx + 0x3ba, struct.pack('<I', r.randrange(0, 5)))
        em.wbytes(cx + 0x3c8, struct.pack('<I', r.getrandbits(32)))
        s1 = bytes(r.choice(b'abcXYZ019') for _ in range(r.randrange(0, 8)))
        s2 = bytes(r.choice(b'abcXYZ019') for _ in range(r.randrange(0, 8)))
        em.wbytes(cx + 0x362, s1 + b'\0')
        em.wbytes(cx + 0x3a2, s2 + b'\0')
        em.calllog.append(('ctor',))
        em.ret(eax=0, argbytes=0)
    e.hook(0x5ad790, ctor)

    def chk(em, res_):
        cx = em.reg('ecx')
        em.calllog.append(('5adeb0', em.arg32(0), em.rbytes(cx + 0x86, 4)))
        em.ret(eax=r.choice([0, 1]), argbytes=4)
    e.hook(0x5adeb0, chk)

    def t710(em, res_):
        em.calllog.append(('563710', em.reg('ecx') != 0, em.arg32(0), _cstr(em, em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    e.hook(0x563710, t710)
    hook_rec(c, 0x5ae450, 1, pop=4)
    hook_rec(c, 0x5ae900, 1, pop=4)
    hook_rec(c, 0x5618b0, 2, this=True, pop=8)
    hook_rec(c, 0x56c780, 1, this=True, pop=4)
    return [this, r.randrange(0, 4)]


S(0x56b460, 'GUESS refresh entry panel texts', 'thiscall', None, ret=None, gen=_g56b460, note='batch38072')
