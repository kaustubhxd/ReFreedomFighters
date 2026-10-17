"""specs_s295.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x5aac30, a long straight sequence of vtable calls
on obj (the stack argument) after exe 0x45f960 returns true. Slot 0x10 is called with one argument (array walks) and with two
(two fixed calls); the stub pops by its return address. Exe helpers 0x45f960 and 0x5aabe0 run as original code."""
import struct
from pilot import S, F, f32


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-1e4, 1e4)))[0]


def _vt_handlers(e, name, slots_args, two_arg_this=None):
    """A vtable whose handlers log (slot, args). Slot 0x10 takes two arguments when called on the object obj (two_arg_this),
    one argument on the element objects (the array walks)."""
    def mk(off):
        def h(em, r):
            if off == 0x10:
                n = 2 if (two_arg_this is not None and em.reg('ecx') == two_arg_this[0]) else 1
            else:
                n = slots_args.get(off, 1)
            args = tuple(em.arg32(k) for k in range(n))
            em.calllog.append((name, off, em.reg('ecx'), args))
            em.ret(eax=0, argbytes=4 * n)
        return h
    slots = {off: mk(off) for off in (0x10, 0x3c, 0x44, 0x4c, 0x60, 0x64)}
    return e.fake_vtable(name, 0x64 // 4 + 1, slots)


def _seq(c):
    e = c.emu

    def h5aab(em, r):                    # GUESS call-recording stub for exe helper 0x5aabe0 (thiscall, one argument)
        em.calllog.append(('ext5aabe0', 0x5aabe0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.hook(0x5aabe0, h5aab)

    def h45f9(em, r):                    # exe helper 0x45f960 (thiscall, one argument, returns al): hooked, recorded, returns true
        em.calllog.append(('ext45f960', 0x45f960, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=1, argbytes=4)
    e.hook(0x45f960, h45f9)
    obj_holder = [0]
    obj_vt = _vt_handlers(e, 'obj5aac', {0x3c: 1, 0x44: 1, 0x4c: 1, 0x60: 1, 0x64: 1}, two_arg_this=obj_holder)
    obj = _rnd(c, 0x40)
    e.w32(obj, obj_vt)
    obj_holder[0] = obj
    el_vt = _vt_handlers(e, 'el5aac', {})
    el_list = []
    for _ in range(3):
        el = _rnd(c, 0x40)
        e.w32(el, el_vt)
        el_list.append(el)
    self_ = _rnd(c, 0x1000)
    for off in (0x2fc, 0x358, 0x35c, 0x42c, 0x3c8, 0x3d0, 0x374):
        e.w32(self_ + off, _fl(c))
    # the three element arrays (begin, end) at +0x659/+0x65d, +0x665/+0x669, +0x671/+0x675
    for beg_off in (0x659, 0x665, 0x671):
        n = c.rng.randrange(0, 3)
        arr = _rnd(c, 4 * 4 + 8)
        for i in range(n):
            e.w32(arr + 4 * i, c.rng.choice(el_list))
        e.w32(self_ + beg_off, arr)
        e.w32(self_ + beg_off + 4, arr + 4 * n)
    eng = _rnd(c, 0x200)
    sub = _rnd(c, 0x200)
    e.w32(eng + 0x190f, sub)
    e.w8(sub + 0x81, c.rng.getrandbits(8))
    e.w32(0x70039c, eng)
    e.w32(self_ + 0x14, c.rng.getrandbits(32))
    # ext 0x45f960 (batch 197's helper): calls obj.vtbl[0x3c] with [this+0x14] and then with its own answer; returns true
    return [self_, obj]


S(0x5aac30, 'longSeq (GUESS)', 'thiscall', None, ret='al', gen=_seq, note='batch295; exe 0x45f960, 0x5aabe0; ret 4')
