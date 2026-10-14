"""specs_s34087.py - five queue items.
0x63a2e0: register ABI (ecx = n, edx = data, stack mn, mx), n in 0..5, components around the initial bounds. 0x4d2c00: the exe table at 0x6e7a30 (18 entries of 20 bytes) is rewritten with lengths 0..4 and bytes that match the argument in a half of the entries;
0x44bcf0: random blocks, this == src in a tenth of the cases. 0x56a080 / 0x576320: hooked callee (plain) and tail target (one stack arg, this recorded)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g63a2e0(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3, 5])
    data = rnd(c, 0x100)
    vals = [0xfffffffb, 0, 5, 100, 254, 255, 256, 300, 0x7fffffff, 0x80000000]
    for i in range(n * 4):
        c.emu.w32(data + 4 * i, r.choice(vals + [r.getrandbits(32)]))
    return [n, data, rnd(c, 0x10), rnd(c, 0x10)]


def _g4d2c00(c):
    clear_hooks(c)
    r = c.rng
    if r.random() < 0.1:
        return [0]
    s = rnd(c, 0x10)
    sb = bytes(c.emu.rbytes(s, 8))
    tab = bytearray()
    cap = r.choice([1, 2, 4, 4])
    for e in range(18):
        L = min(cap, r.choice([0, 1, 2, 3, 4, 4]))
        entry = bytearray(r.getrandbits(8) for _ in range(20))
        entry[4:8] = L.to_bytes(4, 'little')
        if r.random() < 0.6:
            for i in range(min(L, 4)):
                entry[3 - i] = sb[i]
            if L and r.random() < 0.3:
                entry[3 - r.randrange(min(L, 4))] ^= 1
        tab += entry
    c.emu.wbytes(0x6e7a30, bytes(tab))
    return [s]


def _g44bcf0(c):
    clear_hooks(c)
    r = c.rng
    src = rnd(c, 0x100)
    me = src if r.random() < 0.1 else rnd(c, 0x100)
    return [me, src]


def _thunk(callee, target):
    def g(c):
        clear_hooks(c)
        r = c.rng
        hook_rec(c, callee, 0, this=True, pop=0, ret=r.getrandbits(32))
        hook_rec(c, target, 1, this=True, ret=r.getrandbits(32))
        return [rnd(c, 0x40), r.getrandbits(32)]
    return g


S(0x63a2e0, 'GUESS component min/max of vectors', ('regs', ['ecx', 'edx', 's', 's']), None, ret=None, gen=_g63a2e0, note='batch34087')
S(0x4d2c00, 'GUESS longest reversed prefix table match', 'stdcall', None, ret='eax', gen=_g4d2c00, note='batch34087')
S(0x44bcf0, 'GUESS copy state fields', 'thiscall', None, ret='eax', gen=_g44bcf0, note='batch34087')
S(0x56a080, 'GUESS call then tail 0x56a140', 'thiscall', None, ret='eax', gen=_thunk(0x562440, 0x56a140), note='batch34087')
S(0x576320, 'GUESS call then tail 0x576330', 'thiscall', None, ret='eax', gen=_thunk(0x573db0, 0x576330), note='batch34087')
