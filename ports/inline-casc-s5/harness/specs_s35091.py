"""specs_s35091.py - 0x573b20 (stdcall(L, name) ret 8, ret='eax'). L: object (slot 0x50: one arg, the iterator out pointer (flag-recorded), writes the next node of a 0..4 node chain or 0) with [L+8] = first node; node+0x54 = record whose +4 is a string
pointer (null in a quarter: the default name "<NONAME>" at 0x67c8e8) among "abc", "abd", "ab", "", "<NONAME>", "x"; name is one of the same strings (an odd/even length mix so both byte-pair paths of the compare run)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g573b20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    words = [b'abc', b'abd', b'ab', b'', b'<NONAME>', b'x', b'abcd', b'a']

    def mkstr():
        p = rnd(c, 0x10)
        e.wbytes(p, r.choice(words) + b'\0')
        return p
    n = r.choice([0, 1, 2, 3, 4])
    nodes = []
    for _ in range(n):
        node = rnd(c, 0x60)
        rec = rnd(c, 0x10)
        e.w32(rec + 4, 0 if r.random() < 0.25 else mkstr())
        e.w32(node + 0x54, rec)
        nodes.append(node)
    L = obj(c, 0x20, {0x50: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.w32(em.arg32(0), nodes[k + 1] if k + 1 < len(nodes) else 0))}, nslots=0x15)
    e.w32(L + 8, nodes[0] if nodes else 0)
    return [L, mkstr()]


S(0x573b20, 'GUESS find list entry by name', 'stdcall', None, ret='eax', gen=_g573b20, note='batch35091')
