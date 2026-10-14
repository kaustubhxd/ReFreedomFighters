"""specs_s38050.py - cascade s8 batch 38050 (0x4f08b0). Node chain at this[0x54] (0..3 nodes whose flag word has bit 0x100000 about half of the time; 0x4db520 follows a per-node next map and
ends the chain with 0); flags this[0x30] drawn from the three tested bits; this[8] block with +0x3c mode bits and +0x24 field, this[4] name (null 25%), this[0xc] -> int; children chain at this[0x50]
(0..3 entries, +0x54 object with slot 0x20c or null). Logger: slot 0x20 returns a stream by line (7-arg printer for line 0x6a3, 3-arg otherwise) whose slot 0x2c is a custom stub logging the C strings."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _cstr(em, p):
    out = b''
    while len(out) < 40:
        b = em.rbytes(p, 1)
        if b == b'\0':
            break
        out += b
        p += 1
    return out


def _g4f08b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def p3(em, res_):
        em.calllog.append(('p3', em.arg32(0), em.arg32(1), _cstr(em, em.arg32(2))))
        em.ret(eax=0, argbytes=0)

    def p7(em, res_):
        em.calllog.append(('p7',) + tuple(em.arg32(i) for i in range(1, 7)) + (_cstr(em, em.arg32(2)),))
        em.ret(eax=0, argbytes=0)
    st3 = obj(c, 0x20, {0x2c: e.stub_fn('p3', p3)})
    st7 = obj(c, 0x20, {0x2c: e.stub_fn('p7', p7)})

    def lg(em, res_):
        line = em.arg32(1)
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), line))
        em.ret(eax=st7 if line == 0x6a3 else st3, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    nn = r.choice([0, 1, 2, 3])
    nodes = []
    for _ in range(nn):
        blk = rnd(c, 0x40)
        fl = r.getrandbits(32) | (0x100000 if r.random() < 0.5 else 0) if True else 0
        fl = (r.getrandbits(32) & ~0x100000) | (0x100000 if r.random() < 0.5 else 0)
        e.wbytes(blk + 0x23, struct.pack('<I', fl))
        t = rnd(c, 0x20)
        e.w32(t + 0xc, blk)
        nd = rnd(c, 0x80)
        e.w32(nd + 0x54, t if r.random() > 0.1 else 0)
        nodes.append(nd)
    nxt = {a: b for a, b in zip(nodes, nodes[1:])}

    def h4db520(em, res_):
        a = em.reg('ecx')
        em.calllog.append(('next', a))
        em.ret(eax=nxt.get(a, 0), argbytes=0)
    e.hook(0x4db520, h4db520)
    txt = e.alloc(16, 1)
    e.wbytes(txt, b'obj text\0')
    hook_rec(c, 0x4cc5a0, 0, this=True, ret=txt)
    me = rnd(c, 0x80)
    e.w32(me + 0x54, nodes[0] if nodes else 0)
    e.w32(me + 0x30, r.choice([0, 0x800, 2, 0x40000000, 0x800 | 2, 0x40000802, r.getrandbits(32)]))
    blk8 = rnd(c, 0x80)
    e.w32(blk8 + 0x3c, r.choice([0, 0x400, 0x800, 0xc00, 0x1400, r.getrandbits(32)]))
    e.w32(me + 8, blk8)
    nm = e.alloc(8, 1)
    e.wbytes(nm, b'name\0')
    e.w32(me + 4, nm if r.random() > 0.25 else 0)
    cell = e.alloc(4, 4)
    e.w32(cell, r.getrandbits(32))
    e.w32(me + 0xc, cell)
    kids = []
    for _ in range(r.choice([0, 1, 2, 3])):
        k = rnd(c, 0x80)
        e.w32(k + 0x54, obj(c, 0x40, {0x20c: pystub(c, 2, this=True)}) if r.random() > 0.3 else 0)
        kids.append(k)
    for a, b in zip(kids, kids[1:]):
        e.w32(a + 0x60, b)
    if kids:
        e.w32(kids[-1] + 0x60, 0)
    e.w32(me + 0x50, kids[0] if kids else 0)
    a = rnd(c, 0x20)
    return [me, a, r.getrandbits(32)]


S(0x4f08b0, 'GUESS log node info and children', 'thiscall', None, ret=None, gen=_g4f08b0, note='batch38050')
