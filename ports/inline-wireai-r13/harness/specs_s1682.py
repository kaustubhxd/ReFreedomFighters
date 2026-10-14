"""specs_s1682.py - residue 13 batch 1682: three forwarders (0x47fa50, 0x47fa90, 0x47fad0). The ZBaseGeom thunks 0x45fc70,
0x45fc80 and 0x45fd20 are hooked by address (one, two, one stack arguments; thiscall); the manager's slot 0x58 returns a
random object (or zero) whose slots 0x6c (one argument), 0x70 (one) and 0x74 (two) are recorders with random eax."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _gen(hooks):
    def gen(c):
        seq = Seq(c)
        r = c.rng
        clear_hooks(c)
        for addr, nargs in hooks:
            hook(c, seq, addr, nargs, ret=0, this=True, pop=True)
        target = obj(c, 0x40, {0x6c: stub(c, seq, 1, ret=r.getrandbits(32)),
                               0x70: stub(c, seq, 1, ret=r.getrandbits(32)),
                               0x74: stub(c, seq, 2, ret=r.getrandbits(32))})
        mgr = obj(c, 0x100, {0x58: stub(c, seq, 1, ret=target if r.random() < 0.8 else 0)})
        sysobj(c, db=mgr)
        me = rnd(c, 0x40)
        return [me] + [r.getrandbits(32) for _ in range(len(hooks) and (2 if any(n == 2 for _, n in hooks) else 1))]
    return gen


S(0x47fa50, 'GUESS FUN_47fa50', 'thiscall', None, ret='eax', gen=_gen([(0x45fc70, 1)]), note='batch1682; SetMat thunk hooked')
S(0x47fa90, 'GUESS FUN_47fa90', 'thiscall', None, ret='eax', gen=_gen([(0x45fc80, 2)]), note='batch1682; SetMatPos thunk hooked')
S(0x47fad0, 'GUESS FUN_47fad0', 'thiscall', None, ret='eax', gen=_gen([(0x45fd20, 1)]), note='batch1682; SetPos thunk hooked')
