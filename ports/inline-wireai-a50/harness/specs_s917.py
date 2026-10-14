"""specs_s917.py - batch 917: 0x45f3c0 (thiscall, one stack arg (stream), ret 4, returns al = 1). The stream's slot +0x40 writes a drawn
dword to its pointer (twice); this's slot +0x40 is a stand-in (logs, no args). The sub-object at this+0x10 gets its +0x18 word when the
second read is nonzero. Heap writes compared."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    vals = [r.choice([0, r.getrandbits(32)]), r.choice([0, r.getrandbits(32)])]

    def s40(e, rr):
        k = len(seen)
        seen.append(1)
        v = vals[k % 2] if k < 2 else 0
        e.w32(e.arg32(0), v)
        e.calllog.append(('stream.40', e.arg32(0) != 0, v))
        e.ret(eax=0, argbytes=4)

    def self40(e, rr):
        e.calllog.append(('self.40',))
        e.ret(eax=0, argbytes=0)

    seen = []
    stream = vt_object(c, 0x40, {0x40: s40}, nslots=0x20, name='stream')
    me = vt_object(c, 0x40, {0x40: self40}, nslots=0x20, name='self')
    sub = rnd(c, 0x40)
    e.w32(me + 0x10, sub)
    return [me, stream]


S(0x45f3c0, 'read45f3c0 (no name in map)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch917 (residue-9 slice)')
