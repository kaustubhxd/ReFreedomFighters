"""specs_s42005.py - Sonnet t3 batch 42005. 0x424650: cdecl varargs forwarder. Hooked: 0x633654 (ECX = cookie), logger 0x700390 slot 0x4c (3 args, callee pops 12, writes 16 bytes
into the buffer, records the fmt and the two vararg dwords), node slot 0x124 (cdecl 4 args, records node/a/b and the first 16 buffer bytes). Engine float +0x9c7 is 0 in about a third of the cases."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def g424650(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    so = sysobj(c)
    e.wbytes(so + 0x9c7, struct.pack('<I', r.choice([0, 0x80000000, 0x3f800000, 0x7fc00000, r.getrandbits(32)])))

    def put(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(16)))
    lvt = e.alloc(0x80, 4)
    e.w32(lvt + 0x4c, pystub(c, 3, this=True, pop=12, nullflag=(0,), deref={2: 2}, side=put))
    lg = rnd(c, 16)
    e.w32(lg, lvt)
    e.w32(0x700390, lg)
    n = r.choice([0, 1, 1, 2, 3])
    head = 0
    for _ in range(n):
        nd = obj(c, 0x20, {0x124: pystub(c, 4, pop=0, deref={3: -16})})
        e.w32(nd + 8, head)
        head = nd
    owner = rnd(c, 0x1a00)
    e.wbytes(owner + 0x190f, struct.pack('<I', head))
    return [owner, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x424650, 'GUESS log message to each node in the chain (GS, cdecl varargs)', 'cdecl', None, ret=None, gen=g424650, note='batch42005')
