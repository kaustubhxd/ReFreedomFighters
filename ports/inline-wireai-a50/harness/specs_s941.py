"""specs_s941.py - area 50 batch 941: 0x573d40 (thiscall, no args, ret 0: a loop over a signed count of object pointers, slot +0xbc with 1 and slot
+0x284 with 0x677b5a per entry, then this+0x202 = 0) and 0x547760 (thiscall, index and source pointer, ret 8: copies three dwords into the
record at this+0xf + 0x34*index + 0xc). The objects' slots log their arguments; the count is drawn from -1 to 3 so the loop body runs and does not run."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen573(c):
    e, r = c.emu, c.rng

    def hbc(e, rr):
        e.calllog.append(('bc', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h284(e, rr):
        e.calllog.append(('284', e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    only_hooks(c, {})
    self = rnd(c, 0x210)
    cnt = r.choice([-1, 0, 1, 2, 3])
    e.w32(self + 0x1fe, cnt & 0xffffffff)
    for i in range(4):
        o = vt_object(c, 0x40, {0xbc: hbc, 0x284: h284}, nslots=0x200, name='o%d' % i)
        e.w32(self + 0x190 + 4 * i, o)
    e.w32(self + 0x202, r.getrandbits(32))
    return [self]


def _gen547(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x100)
    buf = rnd(c, 0x400)
    e.w32(self + 0xf, (buf - 0xc) & 0xffffffff)     # destination = buf + 0x34*a
    src = rnd(c, 0x20)
    for k in range(3):
        e.w32(src + 4 * k, r.getrandbits(32))
    a = r.randint(0, 5)
    return [self, a, src]


S(0x573d40, 'loop over entries (no name in map)', 'thiscall', None, gen=_gen573, note='area50 batch941 (label D)')
S(0x547760, 'copy record (no name in map)', 'thiscall', None, gen=_gen547, note='area50 batch941 (label D)')
