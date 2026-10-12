"""specs_s1033.py - unclaimed-04 batch 33 (docs/20-unclaimed-04.md): three slice-3 functions (GUESS labels).
0x42d270 (thiscall, one stack argument, ret 4): a flag at N[-2] gates N[-1] = (N[-1] == 0); *Q advances by 0xc unless it equals
R+4. 0x64fcb0 (thiscall, plain ret): result = (int)(float)((double)(float)vt[0xdc]() / (double)vt[0xf8]()), the slot-0xf8 value
returned in st0. 0x5f94f0 (ret 4): the logger; global 0x700390 is a non-zero object whose slot 0x20 returns a logger L; L's
slot 0x2c (cdecl) records its three arguments; global 0x7003b0 is 0 or a recording stub. Vtable slots are recording stubs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fp(c):
    return c.rng.choice([1.0, -2.5, 3.0, 0.0, 1e6, c.rng.uniform(-100.0, 100.0)])


def _args42(c):
    self_o = _rnd(c, 0x2000)
    base = _rnd(c, 0x40)
    N = base + 8
    c.emu.w32(N - 8, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    c.emu.w32(N - 4, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    P = _rnd(c, 0x100)
    c.emu.w32(P + 4, N)
    c.emu.w32(self_o + 0x1b61, P)
    R = _rnd(c, 0x100)
    c.emu.w32(self_o + 0x1b6d, R)
    Q = c.emu.alloc(4, 4)
    cur = c.rng.choice([c.rng.getrandbits(32), 0])
    if c.rng.random() < 0.4:
        c.emu.w32(R + 4, cur)  # the equal case: no advance
    else:
        c.emu.w32(R + 4, c.rng.getrandbits(32))
    c.emu.w32(Q, cur)
    return [self_o, Q]


def _args64(c):
    o = _rnd(c, 0x100)
    ival = c.rng.choice([0, 1, -1, 7, c.rng.randrange(-1000, 1000)]) & 0xffffffff
    yval = _fp(c)

    def h_dc(em, r):
        em.calllog.append(('vt.dc', 0, em.reg('ecx'), ()))
        em.ret(eax=ival, argbytes=0)

    def h_f8(em, r):
        em.calllog.append(('vt.f8', 0, em.reg('ecx'), ()))
        em.ret(st0=yval, argbytes=0)

    vt = c.emu.fake_vtable('metric', 0xf8 // 4 + 1, {0xdc: h_dc, 0xf8: h_f8})
    c.emu.w32(o, vt)
    return [o]


def _setup_logger(c):
    def h_20(em, r):
        em.calllog.append(('obj.20', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1))))
        em.ret(eax=L, argbytes=8)

    def h_2c(em, r):
        em.calllog.append(('L.2c', 0, 0, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=0)

    L_vt = c.emu.fake_vtable('logger L', 0x2c // 4 + 1, {0x2c: h_2c})
    L = c.emu.alloc(0x40, 4)
    c.emu.w32(L, L_vt)
    obj_vt = c.emu.fake_vtable('logger obj', 0x20 // 4 + 1, {0x20: h_20})
    obj = c.emu.alloc(0x100, 4)
    c.emu.w32(obj, obj_vt)
    c.emu.w32(0x700390, obj)
    # a null callback reaches an int3 assert at 0x5f9528, so the contract is non-null: the spec always sets a stub
    def h_cb(em, r):
        em.calllog.append(('7003b0', 0, 0, ()))
        em.ret(eax=0, argbytes=0)

    c.emu.w32(0x7003b0, c.emu.stub_fn('cb7003b0', h_cb))


def _args5f(c):
    return [c.rng.getrandbits(32)]


S(0x42d270, 'unknown::flag_gate_advance_c (unknown) thiscall', 'thiscall', None, ret=None, gen=_args42,
  note='unclaimed-04 batch 33; one stack argument (ret 4)')
S(0x64fcb0, 'unknown::int_ratio_vt_dc_f8 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args64,
  note='unclaimed-04 batch 33; vt 0xdc int, vt 0xf8 float in st0 (GUESS)')
S(0x5f94f0, 'unknown::logger_once (unknown) stdcall', 'stdcall', None, ret='eax', gen=_args5f,
  setup=_setup_logger, note='unclaimed-04 batch 33; logger global 0x700390 non-zero and stubbed (area 70 model)')
