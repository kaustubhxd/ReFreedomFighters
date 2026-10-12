"""specs_s6520.py - unclaimed-68 batch 52 (claim 52): ZGeomSpawn::FrameUpdate (0x4a7c30, GUESS name), thiscall, void, plain ret.
The object has a holder P (this+0x44) whose +8 is an object Q that the exe helper 0x4db2c0 fills; P's slot +0x20 gives R (slots +0x1e0,
+0x98, +0x20); the exe helper 0x4db2f0 is hooked to return Q2 (slot +0x94). The manager (engine+0x9b) slot +0x58 returns X or 0
(X's slot +0x1bc returns Y or 0; Y's slot +0x2c). Float constant at 0x678620 is 1024.0, so this+0x52 stays in [0.002, 0.05] to advance by >= 1.
Stack-frame pointers passed to the slots are logged as '&stk' (the port's locals sit at other addresses than the original's)."""
import struct
from pilot import S
from pe_emu import STACK_TOP
from engine_stubs import zero_obj, set_global


def _f32(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _is_stk(v):
    return STACK_TOP - 0x20000 <= v < STACK_TOP


def _vt(c, name, slots):
    """slots: {byte_off: (nargs, fn(emu, args) -> (eax, st0))}. Undeclared slots stop the run (not called by either side)."""
    fake = {}
    for off, (n, f) in slots.items():
        def h(e, r, off=off, n=n, f=f):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple('&stk' if _is_stk(a) else a for a in args)))
            eax, st0 = f(e, args)
            e.ret(eax=eax, argbytes=4 * n, st0=st0)
        fake[off] = h
    return c.emu.fake_vtable(name, 0x90, fake)


def _obj(c, name, slots, size=0x200):
    o = zero_obj(c, size)
    c.emu.w32(o, _vt(c, name, slots))
    return o


def _noop(e, a):
    return (None, None)


def _const(v):
    return lambda e, a: (v, None)


def _st0(v):
    # a float returned in ST0 (no EAX value)
    return lambda e, a: (None, v)


def _fill(bits_a, bits_b):
    # writes two float[3] outs (arg 0 and arg 1); the same bits go to both runs
    def f(e, a):
        for i in range(3):
            e.w32(a[0] + 4 * i, bits_a[i])
            e.w32(a[1] + 4 * i, bits_b[i])
        return (None, None)
    return f


def _setup(c):
    c.st = {}
    c.emu.hook(0x4db2f0, lambda em, r: (em.calllog.append(('hook4db2f0', 0)), em.ret(eax=c.st['Q2'], argbytes=4)))


def _floats3(c):
    return [_f32(c.rng.uniform(-4.0, 4.0)) for _ in range(3)]


def _gen(c):
    o = zero_obj(c, 0x200)
    # the engine global needs a vtable too: the exe helper 0x4db2c0 reaches engine code through it
    # 0x4e0a10 calls engine slot +0x1c4 with two stack arguments and reads a float from ST0 (fstp)
    eng_f = _f32(c.rng.uniform(-1.0, 1.0))
    eng = _obj(c, 'ZEngineGeom', {0x1c4: (2, _st0(struct.unpack('<f', struct.pack('<I', eng_f))[0]))}, 0x400)
    mgr = zero_obj(c, 0x1000)
    set_global(c, 0x70039c, eng)
    c.emu.w32(eng + 0x40, c.rng.randrange(0, 40))
    c.emu.w32(eng + 0x9b, mgr)
    c.emu.w32(mgr + 0xadc, c.rng.getrandbits(32))

    Y = _obj(c, 'ZGeomSpawnY', {0x2c: (0, _noop)}, 0x80)
    X = _obj(c, 'ZGeomSpawnX', {0x1bc: (7, _const(Y if c.rng.random() < 0.5 else 0)), 0x2c: (0, _noop)})
    c.emu.w32(mgr, _vt(c, 'ZSoundMgrGeom', {0x58: _mgr58(X)}))

    c.st['Q2'] = _obj(c, 'ZGeomSpawnQ2', {0x94: (2, _fill(_floats3(c), _floats3(c)))})

    R2 = _obj(c, 'ZGeomSpawnR2', {}, 0x80)
    R = _obj(c, 'ZGeomSpawnR', {0x1e0: (1, _const(1 if c.rng.random() < 0.5 else 0)),
                                0x98: (2, _fill(_floats3(c), _floats3(c))),
                                0x20: (0, _const(R2))})

    # Q is the object the helper 0x4db2c0 works on; it needs a vtable (its code calls through one)
    Q = _obj(c, 'ZGeomSpawnQ', {off: (0, _noop) for off in range(0, 0x240, 4)})
    P = zero_obj(c, 0x100)
    c.emu.w32(P + 8, Q)
    c.emu.w32(P, _vt(c, 'ZGeomSpawnHolder', {0x20: (0, _const(R))}))

    c.emu.w32(o + 0x44, P)
    c.emu.w32(o + 0x48, c.rng.getrandbits(32))
    c.emu.w32(o + 0x4c, c.rng.randrange(0, 3))
    c.emu.w32(o + 0x72, c.rng.randrange(0, 20))
    c.emu.wbytes(o + 0x7d, bytes([c.rng.randrange(2), c.rng.randrange(2)]))
    c.emu.w32(o + 0x52, _f32(c.rng.uniform(0.002, 0.05)))
    for base in (0x5a, 0x66):
        for i in range(3):
            c.emu.w32(o + base + 4 * i, _f32(c.rng.uniform(-4.0, 4.0)))
    c.emu.w32(o, _vt(c, 'ZGeomSpawnSelf', {0x58: (0, _noop), 0x84: (0, _noop)}))
    return [o]


def _mgr58(X):
    def f(e, a):
        return (X if (a[0] & 1) else 0, None)
    return (1, f)


S(0x4a7c30, 'ZGeomSpawn::FrameUpdate (GUESS) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-68 batch 52; holder P at +0x44; 0x4db2c0/0x4db2f0 helpers; mgr slot +0x58 gives X; vtable slots +0x58/+0x84 on self')
