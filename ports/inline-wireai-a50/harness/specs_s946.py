"""specs_s946.py - area 50 batch 946: 0x562e20 (thiscall, no args, void; two tail jumps and two slot chains) and 0x574200 (thiscall, one word, ret 4,
returns eax). Stand-ins (logged): 0x59c620 (thiscall, no args), 0x562c20 (thiscall, one word, returns a drawn dword). The object's slot +0x84 returns a second
object (the inner) whose slots +0x300 (no args; returns a drawn dword) and +0x2f8 (one word) log. The object's slot +0xd8 returns a drawn dword. The
flags at +0x84, +0x86 and the value at +0x48 are drawn so each branch runs; the word for 0x574200 is drawn equal to 0x2b67 about a third of the time."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _mk(c, want_d8):
    e, r = c.emu, c.rng

    def h300(e, rr):
        e.calllog.append(('inner.300', e.reg('ecx')))
        e.ret(eax=r.getrandbits(32), argbytes=0)

    def h2f8(e, rr):
        e.calllog.append(('inner.2f8', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    inner = vt_object(c, 0x40, {0x300: h300, 0x2f8: h2f8}, nslots=0x200, name='inner')
    return inner


def _gen_562(c):
    e, r = c.emu, c.rng

    def h59c(e, rr):
        e.calllog.append(('59c620', e.reg('ecx')))
        e.ret(eax=0, argbytes=0)

    only_hooks(c, {0x59c620: h59c})
    inner = _mk(c, False)

    def h84(e, rr):
        e.calllog.append(('self.84', e.reg('ecx')))
        e.ret(eax=inner, argbytes=0)

    self_obj = vt_object(c, 0x100, {0x84: h84}, nslots=0x100, name='self')
    e.wbytes(self_obj + 0x84, bytes([r.choice([0, 1])]))
    e.wbytes(self_obj + 0x86, bytes([r.choice([0, 1])]))
    e.w32(self_obj + 0x48, r.choice([0, r.getrandbits(32)]))
    e.w32(self_obj + 0x94, rnd(c, 0x20))
    return [self_obj]


def _gen_574(c):
    e, r = c.emu, c.rng

    def h562(e, rr):
        e.calllog.append(('562c20', e.reg('ecx') != 0, e.arg32(0)))
        e.ret(eax=rv, argbytes=4)

    rv = r.getrandbits(32)
    only_hooks(c, {0x562c20: h562})
    inner = _mk(c, False)

    def h84(e, rr):
        e.calllog.append(('self.84', e.reg('ecx')))
        e.ret(eax=inner, argbytes=0)

    def hd8(e, rr):
        e.calllog.append(('self.d8', e.reg('ecx')))
        e.ret(eax=d8, argbytes=0)

    d8 = r.getrandbits(32)
    if r.random() < 0.6:
        d8 &= 0xffffff00      # low byte clear about 60% of the time, so the 0x2b67 branch runs
    self_obj = vt_object(c, 0x100, {0x84: h84, 0xd8: hd8}, nslots=0x100, name='self')
    v = 0x2b67 if r.random() < 0.35 else r.getrandbits(32)
    return [self_obj, v]


S(0x562e20, 'dispatch with tail jumps (no name in map; 59c620 stood in)', 'thiscall', None, gen=_gen_562, note='area50 batch946 (label A+D)')
S(0x574200, 'check word (no name in map; 562c20 stood in)', 'thiscall', None, ret='eax', gen=_gen_574, note='area50 batch946 (label A+D)')
