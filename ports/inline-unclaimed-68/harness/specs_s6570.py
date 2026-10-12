"""specs_s6570.py - unclaimed-68 batch 57 (claim 58): 0x46b800 (GUESS name), thiscall, two stack args (cmd, obj), ret 8.
Objects: self (fields +0x5c, +0x60, +0x6c, +0x70, +0x7c, +0x7e), the engine manager (engine+0x9b: slot +0x4c, +0x58 maps an argument
to one of four candidate objects or 0), the candidates (slots +0x2e4, +0x2e0, +0x2ec, +0x2f4, +0x210; +0xc -> a struct with a dword at +0x23),
the list head X at self+0x6c (slots +0x4c, +0x64 walks a list of elements, +0x44), obj (slots +0x4c, +0x54, +0x88), and self+0x70 (slot +0x40).
Exe helper 0x45d380 is run as is on the cold path; its own call through self slot +0x16c is logged. Stack-frame pointers are logged as '&stk'."""
import struct
from pilot import S
from pe_emu import STACK_TOP
from engine_stubs import zero_obj, set_global


def _is_stk(v):
    return STACK_TOP - 0x20000 <= v < STACK_TOP


def _vt(c, name, nslots, slots):
    """slots: {byte_off: (nargs, fn(emu, args) -> (eax, st0))}."""
    fake = {}
    for off, (n, f) in slots.items():
        def h(e, r, off=off, n=n, f=f):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple('&stk' if _is_stk(a) else a for a in args)))
            eax, st0 = f(e, args)
            e.ret(eax=eax, argbytes=4 * n, st0=st0)
        fake[off] = h
    return c.emu.fake_vtable(name, nslots, fake)


def _noop(e, a):
    return (None, None)


def _const(v):
    return lambda e, a: (v, None)


def _obj(c, name, slots, size=0x200):
    o = zero_obj(c, size)
    c.emu.w32(o, _vt(c, name, 0x400, slots))
    return o


def _setup(c):
    c.st = {}
    # the cold path (exe helper 0x45d380) is run as is; nothing to hook


def _gen(c):
    rng = c.rng
    self_o = zero_obj(c, 0x200)
    eng = zero_obj(c, 0x400)
    mgr = zero_obj(c, 0x200)
    set_global(c, 0x70039c, eng)
    c.emu.w32(eng + 0x9b, mgr)

    # candidate objects returned by the manager slot +0x58
    cands = []
    for i in range(4):
        s = zero_obj(c, 0x40)
        c.emu.w32(s + 0x23, rng.getrandbits(32))
        name_ptr = 0 if rng.random() < 0.5 else (0x67c8e8 + 4 * rng.randrange(8))
        cand_o = _obj(c, 'Cand%d' % i, {
            0x2e4: (1, _const(rng.randrange(2))),
            0x2e0: (1, _noop),
            0x2ec: (0, _const(rng.randrange(2))),
            0x2f4: (2, _const(rng.randrange(2))),
            0x210: (1, _noop),
        })
        c.emu.w32(cand_o + 0x4, name_ptr)
        c.emu.w32(cand_o + 0xc, s)
        cands.append(cand_o)
    # the manager: slot +0x4c returns a value; slot +0x58 maps its argument to a candidate (or 0)
    v1 = rng.getrandbits(32)
    mgr_map = [rng.randrange(0, 5) for _ in range(8)]  # index into cands; 4 means 0

    def m58(e, a):
        k = mgr_map[a[0] & 7]
        return (0 if k == 4 else cands[k], None)
    c.emu.w32(mgr, _vt(c, 'ZMgr46b800', 0x400, {0x4c: (0, _const(v1)), 0x58: (1, m58)}))

    # list head X at self+0x6c: the elements are small blocks whose first dword is a value; slot +0x64 walks them
    elems = []
    for _ in range(rng.randrange(0, 4)):
        el = zero_obj(c, 0x20)
        c.emu.w32(el, rng.getrandbits(32))
        elems.append(el)
    state = {'i': 0}

    def x4c(e, a):
        state['i'] = 0
        return (None, None)

    def x64(e, a):
        if state['i'] < len(elems):
            v = elems[state['i']]
            state['i'] += 1
            return (v, None)
        return (0, None)
    X = _obj(c, 'ZListHead46b800', {0x4c: (1, x4c), 0x64: (1, x64), 0x44: (1, _noop)})
    o70 = _obj(c, 'ZTarget70', {0x40: (1, _noop)})

    obj = _obj(c, 'ZArg46b800', {0x4c: (2, _noop), 0x54: (2, _noop), 0x88: (2, _noop)})

    c.emu.w32(self_o + 0x60, 0 if rng.random() < 0.2 else rng.getrandbits(32))
    c.emu.w32(self_o + 0x5c, rng.randrange(0, 5))
    c.emu.w32(self_o + 0x6c, X if rng.random() < 0.8 else 0)
    c.emu.w32(self_o + 0x70, o70)
    c.emu.w32(self_o + 0x7c, rng.getrandbits(16))
    c.emu.w32(self_o + 0x7e, rng.getrandbits(16))
    # the self vtable (the cold path's exe helper calls slot +0x16c; the body calls slot +0x318)
    c.emu.w32(self_o, _vt(c, 'ZSelf46b800', 0x400, {0x16c: (2, _noop), 0x318: (0, _noop)}))

    # cmd: its low word matches +0x7c (main path) or +0x7e (path B) about 70% of the time, otherwise random
    w7c = rng.getrandbits(16)
    w7e = rng.getrandbits(16)
    c.emu.wbytes(self_o + 0x7c, struct.pack('<H', w7c))
    c.emu.wbytes(self_o + 0x7e, struct.pack('<H', w7e))
    r = rng.random()
    lo = w7c if r < 0.4 else (w7e if r < 0.7 else rng.getrandbits(16))
    cmd = (rng.getrandbits(16) << 16) | lo
    return [self_o, cmd, obj]


S(0x46b800, 'FUN_46b800 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=_setup,
  note='unclaimed-68 batch 57; list walk over +0x6c, manager slot +0x58, candidate slots; cold path runs exe 0x45d380')
