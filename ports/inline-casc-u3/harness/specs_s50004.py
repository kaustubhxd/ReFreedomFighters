"""specs_s50004.py - u3 (Sonnet) batch 50004, tier H. 0x640590: engine object (+0x9c3 / +0x9c7 floats gate the debug trace slots 0x1c8 (64-bit result, edx set by the stub), 0x178, 0x17c; +0x9b = table with an
unaligned dword at +0x5d35 = helper object with slot 0x14); container at this+0x204 with vtable slots 0xc (begin) and 0x10 (advance, same block walk as the inline code) over a chain of 1-3 blocks
(count at +0, next at +8, entries from +0x10); entries with / without sub-object and flag bit; sub-objects with flags 0x2000000, t objects (slot 0x220) whose type dword at [[t+0xc]+0x23] is 0x80000d
or not; 0x4dbb00 / 0x4dd3d0 hooked."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
from unicorn.x86_const import UC_X86_REG_EDX


def _g640590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dbb00, 1, this=True, pop=4, ret=r.getrandbits(32))
    hook_rec(c, 0x4dd3d0, 0, this=True, ret=r.getrandbits(32))

    def line(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    slots = {0x1c8: pystub(c, 2, this=True, pop=8, ret=lambda em, k: r.getrandbits(32), side=line),
             0x178: pystub(c, 3, this=True), 0x17c: pystub(c, 3, this=True)}
    so = sysobj(c, slots=slots)
    on = r.random() < 0.6
    for off in (0x9c7, 0x9c3):
        v = r.choice([1.0, -2.5, float('nan')]) if on or r.random() < 0.3 else 0.0
        e.wbytes(so + off, struct.pack('<f', v))
    tab = rnd(c, 0x5d60)
    e.wbytes(so + 0x9b, tab.to_bytes(4, 'little'))
    helper = obj(c, 0x20, {0x14: pystub(c, 1, this=True)}, nslots=0x18 // 4)
    e.wbytes(tab + 0x5d35, (helper if r.random() > 0.2 else 0).to_bytes(4, 'little'))

    nelem = r.choice([0, 1, 2, 3, 5, 8])
    elems = []
    for _ in range(nelem):
        el = rnd(c, 0x60)
        if r.random() < 0.8:
            sub = rnd(c, 0x60)
            fl = r.getrandbits(32) & ~0x2000000
            e.w32(sub + 0x3c, fl | (0x2000000 if r.random() < 0.4 else 0))
            t = obj(c, 0x40, {0x220: pystub(c, 1, this=True)}, nslots=0x224 // 4)
            u = rnd(c, 0x40)
            e.wbytes(u + 0x23, struct.pack('<I', 0x80000d if r.random() < 0.5 else r.getrandbits(32)))
            e.w32(t + 0xc, u)
            e.w32(t + 0x18, r.getrandbits(32))
            e.w32(sub + 0x54, t)
            e.w32(el + 0x38, sub)
        else:
            e.w32(el + 0x38, 0)
        e.w32(el + 4, r.getrandbits(32))
        elems.append(el)
    blocks = []
    i = 0
    while i < len(elems):
        n = min(len(elems) - i, r.randrange(1, 4))
        b = rnd(c, 0x10 + 4 * n + 8)
        e.w32(b, n)
        for j in range(n):
            e.w32(b + 0x10 + 4 * j, elems[i + j])
        blocks.append(b)
        i += n
    for j, b in enumerate(blocks):
        e.w32(b + 8, blocks[j + 1] if j + 1 < len(blocks) else 0)
    head = blocks[0] if blocks else 0

    def begin(em, k):
        it = em.arg32(0)
        em.calllog.append(('begin',))
        em.w32(it + 8, head)
        em.w32(it + 4, 0)
        em.w32(it, head + 0x10 if head else 0)
        em.ret(0, 4)

    def adv(em, k):
        it = em.arg32(0)
        em.calllog.append(('adv',))
        idx = em.r32(it + 4) + 1
        em.w32(it + 4, idx)
        node = em.r32(it + 8)
        if idx == em.r32(node):
            node = em.r32(node + 8)
            em.w32(it + 8, node)
            if node == 0:
                cur = 0
            else:
                em.w32(it + 4, 0)
                cur = node + 0x10
        else:
            cur = em.r32(it) + 4
        em.w32(it, cur)
        em.ret(0, 4)
    vt = e.alloc(0x20, 4)
    e.w32(vt + 0xc, e.stub_fn('begin', begin))
    e.w32(vt + 0x10, e.stub_fn('advance', adv))
    me = rnd(c, 0x230)
    e.w32(me + 0x204, vt)
    return [me]


S(0x640590, 'GUESS update sub-objects of listed entries', 'thiscall', None, ret=None, gen=_g640590, note='batch50004')
