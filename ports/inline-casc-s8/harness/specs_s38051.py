"""specs_s38051.py - cascade s8 batch 38051 (0x5fc2f0). A tree head and 1..5 nodes with packed (unaligned) fields: +1 parent, +5 leftmost / left, +9 rightmost / right, +0xd / +0x11 the key range (strings over
{a, b} of length 0..3 so equal / prefix / ordered keys all occur); the hint is begin(), end() or a middle node (chosen by case); tree size +4 is zero 15%. The import 0x676408 (strncmp) is a logged Python stub;
0x42ffc0 (--it) writes the predecessor into the iterator cell, 0x5fb270 returns a random bool, 0x5fb400 writes a random dword through its result pointer, 0x5fc480 returns a cell with a random dword (all args
logged; the iterator temp lives on the stack, so only contents are logged)."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g5fc2f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cmpstub(em, res_):
        a, b, n = em.arg32(0), em.arg32(1), em.arg32(2)
        sa, sb = em.rbytes(a, n) if n > 0 else b'', em.rbytes(b, n) if n > 0 else b''
        em.calllog.append(('cmp', sa, sb, n))
        em.ret(eax=0 if sa == sb else (1 if sa > sb else 0xffffffff), argbytes=0)
    e.w32(0x676408, e.stub_fn('strncmp', cmpstub))

    def mkstr():
        s = bytes(r.choice(b'ab') for _ in range(r.randrange(0, 4)))
        p = e.alloc(8, 1)
        e.wbytes(p, s + b'\0\0\0\0')
        return p, p + len(s)

    def mknode():
        n = e.alloc(0x28, 4)
        e.wbytes(n, r.randbytes(0x28))
        b, en = mkstr()
        e.wbytes(n + 0xd, struct.pack('<II', b, en))
        return n
    head = e.alloc(0x28, 4)
    e.wbytes(head, r.randbytes(0x28))
    nodes = [mknode() for _ in range(r.randrange(1, 6))]
    e.wbytes(head + 5, struct.pack('<I', nodes[0]))
    e.wbytes(head + 9, struct.pack('<I', nodes[-1]))
    for nd in nodes:
        e.wbytes(nd + 9, struct.pack('<I', 0 if r.random() < 0.5 else r.choice(nodes)))
    mode = r.choice(['begin', 'end', 'mid', 'mid'])
    if mode == 'begin':
        hint = nodes[0]
    elif mode == 'end':
        hint = head
    else:
        hint = r.choice(nodes)
    prev = r.choice(nodes)
    me = e.alloc(0x40, 4)
    e.wbytes(me, r.randbytes(0x40))
    e.w32(me, head)
    e.w32(me + 4, 0 if r.random() < 0.15 else r.randrange(1, 9))
    kb, ke = mkstr()
    key = e.alloc(8, 4)
    e.w32(key, kb)
    e.w32(key + 4, ke)
    ret = e.alloc(8, 4)
    e.wbytes(ret, r.randbytes(8))
    cell = e.alloc(8, 4)
    e.wbytes(cell, r.randbytes(8))

    def dec(em, res_):
        it = em.reg('ecx')
        em.calllog.append(('dec', em.r32(it) == hint))
        em.w32(it, prev)
        em.ret(eax=0, argbytes=0)
    e.hook(0x42ffc0, dec)
    hook_rec(c, 0x5fb270, 2, this=True, pop=8, ret=lambda em, k: r.choice([0, 1, 0x101]))
    hook_rec(c, 0x5fb400, 4, this=True, pop=16, side=lambda em, k: em.w32(em.arg32(0), r.getrandbits(32)))

    def h480(em, res_):
        em.calllog.append(('h480', em.reg('ecx'), em.arg32(1), em.rbytes(em.arg32(1), 8)))
        em.ret(eax=cell, argbytes=8)
    e.hook(0x5fc480, h480)
    return [me, ret, hint, key]


S(0x5fc2f0, 'GUESS std::map insert with hint', 'thiscall', None, ret='eax', gen=_g5fc2f0, note='batch38051')
