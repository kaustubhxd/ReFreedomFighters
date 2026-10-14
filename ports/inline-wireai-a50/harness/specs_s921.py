"""specs_s921.py - residue-9 slice, batch 921: 0x499c50 (thiscall, one arg, ret 4, returns this) and 0x5fa090 (thiscall, one index arg, ret 4,
returns a dword). Stand-ins (logged): the manager's slot +0x4c (one arg, returns a drawn dword), the object's slot +0x3c (one arg), and
the engine hook 0x7003b0 (thiscall, no args; installed for the case). The index is drawn below and at the count so the hook runs both ways."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen_a(c):
    e, r = c.emu, c.rng

    def h4c(e, rr):
        e.calllog.append(('mgr.4c', e.arg32(0)))
        e.ret(eax=rv, argbytes=4)

    def h3c(e, rr):
        e.calllog.append(('self.3c', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    rv = r.getrandbits(32)
    only_hooks(c, {})
    mgr = vt_object(c, 0x40, {0x4c: h4c}, nslots=0x40, name='mgr')
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    self = vt_object(c, 0x40, {0x3c: h3c}, nslots=0x40, name='self')
    return [self, r.getrandbits(32)]


def _gen_b(c):
    e, r = c.emu, c.rng
    cnt = r.randint(1, 4)

    def hook(e, rr):
        e.calllog.append(('hook.7003b0', e.reg('ecx') != 0))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {})
    h = e.stub_fn('hook7003b0', hook)
    e.w32(0x7003b0, h)      # always installed: with a null hook the original traps (int3), which is not a passing case
    self = rnd(c, 0x40)
    t = rnd(c, 0x40)
    e.w32(self + 4, t)
    e.w32(t + 0x14, cnt)
    arr = rnd(c, 0x40)
    e.w32(t + 0xc, arr)
    for i in range(16):             # every slot a valid entry: an index past the count reads a valid pointer
        ent = rnd(c, 0x10)
        e.w32(ent, r.getrandbits(32))
        e.w32(arr + 4 * i, ent)
    idx = r.choice([0, cnt - 1, cnt, cnt + 1, r.randint(0, cnt - 1)])
    return [self, idx]


S(0x499c50, 'init with a (no name in map)', 'thiscall', None, ret='eax', gen=_gen_a, note='area50 batch921 (residue-9 slice)')
S(0x5fa090, 'entry by index (no name in map)', 'thiscall', None, ret='eax', gen=_gen_b, note='area50 batch921 (residue-9 slice)')
