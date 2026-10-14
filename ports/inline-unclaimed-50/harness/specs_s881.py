"""specs_s881.py - area 50, batch 881: 0x505090 (GUESS name), thiscall, one stack arg (record), ret 4, returns the value of 0x5002f0.
Stand-ins (hooked, logged): the accessor 0x5003d0 (first call from record+4 gives the key's address, the second from record+8 gives
another address), the log 0x5057e0 (stdcall, ret 8), the method 0x5002f0 (thiscall, ret 4). The object's slot 0x50 takes six words
(ret 0x18) and logs them. Keys are drawn so both the positive branch and the log branch run."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    kval = r.choice([r.randint(1, 50), 0, r.randint(-50, -1), r.getrandbits(32)])
    rv50 = r.getrandbits(32)
    rv2f0 = r.getrandbits(32)
    calls = [0]

    def acc(e, rr):
        calls[0] += 1
        e.calllog.append(('acc.5003d0', calls[0], e.arg32(0)))
        e.ret(eax=(keyp if calls[0] == 1 else valp), argbytes=4)

    def sink(e, rr):
        e.calllog.append(('log.5057e0', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    def f2f0(e, rr):
        e.calllog.append(('f2f0.5002f0', e.arg32(0)))
        e.ret(eax=rv2f0, argbytes=4)

    def m50(e, rr):
        e.calllog.append(('self.50',) + tuple(e.arg32(k) for k in range(6)))
        e.ret(eax=rv50, argbytes=0x18)

    only_hooks(c, {0x5003d0: acc, 0x5057e0: sink, 0x5002f0: f2f0})
    self = vt_object(c, 0x40, {0x50: m50}, nslots=0x60, name='self')
    keyp = rnd(c, 8)
    e.w32(keyp, kval & 0xFFFFFFFF)
    valp = rnd(c, 8)
    e.w32(valp, r.getrandbits(32))
    mgr = rnd(c, 0x80)
    e.w32(mgr + 0x44, r.getrandbits(32))
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    a = rnd(c, 0x40)
    e.w32(a + 4, rnd(c, 0x40))
    e.w32(a + 8, rnd(c, 0x40))
    return [self, a]


S(0x505090, 'Fn505090 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch881')
