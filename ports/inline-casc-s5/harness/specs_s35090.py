"""specs_s35090.py - 0x597680 (thiscall(a, b) ret 8, ret='eax'). this: random 0x2000 bytes with n = [+0x1fae] in 1..5 (an empty or step-skipping walk would never end in the exe either); unaligned id dwords at +0x1dae + 4i; engine table slot 0x58 (1 arg recorded) returns, by call index, objects (0x800-byte blocks
whose dword at +0x77f (read by the real 0x59ffc0) is 5 in a third of them; vtable slot 0x670 (0 args, AL true in half)); a in -2..n+2, b in -1, 0, 1."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g597680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    objs = []
    for _ in range(6):
        o = obj(c, 0x800, {0x670: pystub(c, 0, this=True, ret=(r.getrandbits(24) << 8) | (r.choice([1, 2, 0x80]) if r.random() < 0.5 else 0))}, nslots=0x1a0)
        e.wbytes(o + 0x77f, (5 if r.random() < 1 / 3 else r.choice([0, 1, 2, 6, r.getrandbits(32)])).to_bytes(4, 'little'))
        objs.append(o)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[k % 6])})
    me = rnd(c, 0x2000)
    n = r.randint(1, 5)
    e.w32(me + 0x1fae, n)
    return [me, r.randint(-2, n + 2) & 0xffffffff, r.choice([-1, 0, 1, 1, -1]) & 0xffffffff]


S(0x597680, 'GUESS next usable slot in circular table', 'thiscall', None, ret='eax', gen=_g597680, note='batch35090')
