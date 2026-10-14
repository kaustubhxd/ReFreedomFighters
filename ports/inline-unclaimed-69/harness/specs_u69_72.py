"""specs_u69_72.py - area 69, group 72 (slice 8): 0x42ffc0, a walk over a node list (no callees). The pool has four nodes (0x20 bytes each) and a sentinel
node S whose +5 is not a node address (so the back-walk stops there). The +9 links go forward, the +1 links go back, so the walks end.
Links are either valid nodes or zero, and each zero is checked by the code before it is read. eax is not compared (ret=None)."""
from pilot import S
from ckit import rnd


def _walk(c):
    e = c.emu
    r = c.rng
    K = 4
    pool = rnd(c, 0x20 * (K + 1) + 0x10)
    nodes = [pool + 0x20 * i for i in range(K)]
    sent = pool + 0x20 * K
    e.w32(sent + 5, 0)
    e.w32(sent + 9, 0)
    e.w32(sent + 1, sent)
    e.wbytes(sent, bytes([0]))
    for i, n in enumerate(nodes):
        e.wbytes(n, bytes([0 if r.random() < 0.6 else r.getrandbits(8)]))
        e.w32(n + 9, nodes[i + 1] if i + 1 < K and r.random() < 0.8 else 0)
        back = nodes[i - 1] if i > 0 else sent
        e.w32(n + 1, back)
        e.w32(n + 5, r.choice([0, sent, back, nodes[i + 1] if i + 1 < K else 0]))
    slot = rnd(c, 8)
    P = r.choice(nodes + [sent])
    e.w32(slot, P)
    return [slot]


S(0x42ffc0, 'nextNode42ffc0 (thiscall, no args, void)', 'thiscall', None, ret=None, gen=_walk, note='u69 group 72; no callees; eax not compared')
