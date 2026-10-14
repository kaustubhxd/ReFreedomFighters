"""specs_u69_78.py - area 69, group 78 (slice 8): five small functions, no callees. Chains are acyclic (forward links only) so the loops end."""
from pilot import S
from ckit import rnd


def _410(c):
    return [rnd(c, 0x20), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _658(c):
    return [c.rng.getrandbits(32)]


def _eb40(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x3420)
    cnt = r.randrange(0, 5)
    e.w32(self_ + 0x3408, cnt)
    for i in range(cnt):
        k = r.randrange(0, 4)
        nodes = [rnd(c, 0x10) for _ in range(k)]
        for j, nd in enumerate(nodes):
            e.w32(nd + 4, r.getrandbits(32))
            e.w32(nd + 8, nodes[j + 1] if j + 1 < k else 0)
        e.w32(self_ + 4 * i, nodes[0] if nodes else 0)
    return [self_]


def _41d(c):
    e = c.emu
    r = c.rng
    s = rnd(c, 0x40)
    n = r.randrange(0, 0x20)
    alpha = b'abc.\\/:Z'
    data = bytes(r.choice(alpha) for _ in range(n)) + b'\x00'
    e.wbytes(s, data + bytes(8))
    return [s]


def _534(c):
    e = c.emu
    r = c.rng
    base = rnd(c, 8 * 10 + 8)
    K = 8
    for k in range(K):
        e.w32(base + 8 * k + 4, r.choice([0, 0x80000000] + [kk for kk in range(k + 1, K)]))
    e.w32(base + 8 * K + 4, 0)   # entry K is reachable (a link to K-1 points past the last written entry); its +4 must end the chain
    arg = r.choice([0, 0x80000000] + list(range(0, K)))
    return [base, arg]


S(0x410bc0, 'cdecl410bc0 (cdecl, three args, void)', 'cdecl', None, ret=None, gen=_410, note='u69 group 78')
S(0x658180, 'stdcall658180 (stdcall, one arg, void)', 'stdcall', None, ret=None, gen=_658, note='u69 group 78; writes the float global 0x6f6318')
S(0x63eb40, 'max63eb40 (thiscall, no args, returns the max)', 'thiscall', None, ret='eax', gen=_eb40, note='u69 group 78')
S(0x41d500, 'lastSep41d500 (thiscall, no args, returns a pointer)', 'thiscall', None, ret='eax', gen=_41d, note='u69 group 78')
S(0x534100, 'count534100 (thiscall, one arg, ret 4, returns the count)', 'thiscall', None, ret='eax', gen=_534, note='u69 group 78')
