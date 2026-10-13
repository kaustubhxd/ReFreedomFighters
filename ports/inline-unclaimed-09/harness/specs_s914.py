"""specs_s914.py - unclaimed-09 batch 6 (docs/20-unclaimed-09.md, claim 6): ZDamageBox::FrameUpdate.

No arguments; the object is 0x100 random bytes. Every virtual call is a Python handler (unverified callees):
- the list (this+0x84): vt+0x4c (Begin; one argument, the ok pointer; logged; pops 4 bytes) and vt+0x5c (Next: yields 0 to 3 items,
  writing ok at the pointer argument; logged with the index).
- each item's obj: vt+0x438 (returns a random al; logged), vt+0x84 (logs the 12 bytes of vec), vt+0x128 (logs the word).
- this+0x44: vt+0x8c (logs vec) and vt+0x180 (logs vec and the float bits; returns a random al).
- the global object at 0x70039c (written by the spec each run): +0x9b points to an object whose vt+0x114 logs its six
  arguments and returns a random word.
ext 0x4daf90 is the original code and runs unchanged. Stack pointers are never logged (they differ between exe and port);
only heap values and vector contents are."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fbits(c, lo, hi):
    if c.rng.random() < 0.02:
        return c.rng.getrandbits(32)     # NaN, inf and denormal patterns too
    return struct.unpack('<I', struct.pack('<f', c.fv(lo, hi)))[0]


def _vec_bytes(e, p):
    return bytes(e.rbytes(p, 12))


def _gen(c):
    e = c.emu
    rng = c.rng
    log_names = []

    # the global object (render manager stand-in): f48 at +0x48, pointer to a 0x114 object at +0x9b
    gobj_word = rng.getrandbits(16)
    state = {'i': 0, 'items': []}

    def sweep114(e2, r):
        args = tuple(e2.arg32(k) for k in range(4))
        e2.calllog.append(('Sweep114', args[0], args[1], args[2], args[3]))
        e2.ret(eax=gobj_word, argbytes=16)

    def _half(e2, p):
        return bytes(e2.rbytes(p, 4))

    def sweep128(e2, r):
        p = e2.arg32(1)
        e2.calllog.append(('Sweep128', e2.arg32(0), _half(e2, p), e2.arg32(2)))
        e2.ret(eax=0, argbytes=12)

    def vec84(e2, r):
        e2.calllog.append(('Vec84', _vec_bytes(e2, e2.arg32(0))))
        e2.ret(eax=0, argbytes=4)

    def vec8c(e2, r):
        e2.calllog.append(('Vec8c', _vec_bytes(e2, e2.arg32(0))))
        e2.ret(eax=0, argbytes=4)

    pred_al = rng.getrandbits(1)
    fire_al = rng.getrandbits(1)

    def pred438(e2, r):
        e2.calllog.append(('Pred438',))
        e2.ret(eax=pred_al, argbytes=0)

    def fire180(e2, r):
        e2.calllog.append(('Fire180', _vec_bytes(e2, e2.arg32(0)), e2.arg32(1)))
        e2.ret(eax=fire_al, argbytes=8)

    def begin4c(e2, r):
        e2.calllog.append(('Begin4c',))
        e2.ret(eax=0, argbytes=4)

    def next5c(e2, r):
        okp = e2.arg32(0)
        if state['i'] < len(state['items']):
            e2.w32(okp, 1)
            e2.calllog.append(('Next5c', state['i']))
            res = state['items'][state['i']]
            state['i'] += 1
            e2.ret(eax=res, argbytes=4)
        else:
            e2.w32(okp, 0)
            e2.calllog.append(('Next5c', 'end'))
            e2.ret(eax=0, argbytes=4)

    gobj = e.fake_object('gobj', 0x40, slots={0x114: sweep114})
    g = _rnd(c, 0x100)
    e.w32(g + 0x9b, gobj)
    e.w32(g + 0x48, _fbits(c, 0.0, 1.0))
    e.w32(0x70039c, g)

    o44 = e.fake_object('o44', 0x40, slots={0x8c: vec8c, 0x180: fire180})
    self_ = _rnd(c, 0x100)
    e.w32(self_ + 0x44, o44)
    e.w32(self_ + 0x4c, _fbits(c, 0.0, 1.0))
    e.w32(self_ + 0x50, _fbits(c, 0.0, 2.0))
    e.w32(self_ + 0x54 + 0, rng.getrandbits(32))

    if rng.random() < 0.1:
        e.w32(self_ + 0x84, 0)
    else:
        lst = e.fake_object('list', 0x20, slots={0x4c: begin4c, 0x5c: next5c})
        e.w32(self_ + 0x84, lst)
        for _ in range(rng.randint(0, 3)):
            item = _rnd(c, 0x20)
            sub = _rnd(c, 0x40)
            for k in range(3):
                e.w32(sub + 0x30 + 4 * k, rng.getrandbits(32))
            iobj = e.fake_object('iobj', 0x40, slots={0x438: pred438, 0x84: vec84, 0x128: sweep128})
            e.w32(iobj + 8, sub)
            e.w32(item + 4, iobj)
            e.w8(item + 8, 0 if rng.random() < 0.7 else 1)
            if rng.random() < 0.25:
                # f9 exactly equal to the timer after this frame's add: f9 - timer == 0 (the boundary case)
                tsum = struct.unpack('<f', struct.pack('<f', struct.unpack('<f', e.rbytes(g + 0x48, 4))[0] + struct.unpack('<f', e.rbytes(self_ + 0x4c, 4))[0]))[0]
                e.w32(item + 9, struct.unpack('<I', struct.pack('<f', tsum))[0])
            else:
                e.w32(item + 9, _fbits(c, -2.0, 2.0))
            state['items'].append(item)
    return [self_]


S(0x5db180, 'ZDamageBox::FrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-09 b6; vtable calls stubbed (unverified callees); ext 0x4daf90 original')
