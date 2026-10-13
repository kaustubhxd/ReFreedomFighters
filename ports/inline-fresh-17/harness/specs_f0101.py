"""specs_f0101.py - fresh slice 17, batch 1. Every vtable slot and hooked callee logs its arguments (never a stack
address) and returns a per-case random value, so wrong order, wrong argument or a dropped call shows in the call log."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, name, nslots, spec):
    """spec: {off: (argwords, pop_bytes, log_ecx)}; each slot logs and returns a fresh random eax."""
    e = c.emu
    slots = {}
    for off, (nw, pop, lecx) in spec.items():
        rv = c.rng.getrandbits(32)

        def h(e, r, off=off, nw=nw, pop=pop, lecx=lecx, rv=rv):
            args = tuple(e.arg32(k) for k in range(nw))
            e.calllog.append((name, off, e.reg('ecx') if lecx else 0, args, rv))
            e.ret(eax=rv, argbytes=pop)
        slots[off] = h
    return e.fake_vtable(name, max(spec) // 4 + 1, slots)


def _hook(c, addr, nw, pop, lecx=True, rv=None):
    rv = c.rng.getrandbits(32) if rv is None else rv

    def h(e, r):
        e.calllog.append(('hook', addr, e.reg('ecx') if lecx else 0, tuple(e.arg32(k) for k in range(nw)), rv))
        e.ret(eax=rv, argbytes=pop)
    c.emu.hook(addr, h)


def _obj(c, size, vt):
    o = _rnd(c, size)
    c.emu.w32(o, vt)
    return o


def _g54c3d0(c):
    e = c.emu
    self_o = _rnd(c, 0x6400)
    if c.rng.random() < 0.3:
        e.w32(self_o + 0x63ec, 0)
    else:
        e.w32(self_o + 0x63ec, _obj(c, 0x20, _vt(c, 'p', 20, {0x48: (1, 4, False)})))
    _hook(c, 0x54ab70, 0, 0)
    return [self_o]


def _g650b50(c):
    self_o = _obj(c, 0x80, _vt(c, 'rb', 40, {0x90: (0, 0, True), 0x9c: (1, 4, True)}))
    return [self_o, c.rng.getrandbits(32)]


def _g64f9d0(c):
    e = c.emu
    g = _obj(c, 0x20, _vt(c, 'g8c', 40, {0x98: (0, 0, True)}))
    e.w32(0x70038c, g)
    return [_obj(c, 0x40, _vt(c, 'r', 40, {0x74: (2, 8, True)}))]


def _g657450(c):
    e = c.emu
    p1, p2 = _rnd(c, 0x100), _rnd(c, 0x100)
    vals = [p1, p2]

    def h(e, r):
        a = e.arg32(0)
        v = vals.pop(0) if vals else 0
        e.calllog.append(('pc', 0xc, e.reg('ecx'), a, v))
        e.ret(eax=v, argbytes=4)
    vt = e.fake_vtable('pc', 8, {0xc: h})
    return [_obj(c, 0x40, vt), c.rng.getrandbits(32)]


def _g57aa50(c):
    self_o = _obj(c, 0x40, _vt(c, 'w', 40, {0x64: (1, 4, True)}))
    _hook(c, 0x562e90, 2, 8)
    return [self_o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g650dd0(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    if c.rng.random() < 0.3:
        e.w32(self_o + 0x8c, 0)
    else:
        e.w32(self_o + 0x8c, _obj(c, 0x20, _vt(c, 'old', 4, {0: (1, 4, True)})))
    return [self_o, c.rng.getrandbits(32)]


def _glog(c):
    e = c.emu
    rv = c.rng.getrandbits(32)

    def log2c(e, r):
        e.calllog.append(('log', 0x2c, e.arg32(0), e.arg32(1)))
        e.ret(eax=rv, argbytes=0)       # cdecl
    log = _obj(c, 0x20, e.fake_vtable('log', 12, {0x2c: log2c}))
    mgr = _obj(c, 0x20, _vt(c, 'mgr', 10, {0x20: (2, 8, True)}))
    # the manager's slot +0x20 returns the log object
    e.w32(mgr, e.fake_vtable('mgr', 10, {0x20: (lambda e, r: (e.calllog.append(('mgr', 0x20, e.reg('ecx'), e.arg32(0), e.arg32(1))), e.ret(eax=log, argbytes=8)))}))
    e.w32(0x700390, mgr)
    return [c.rng.getrandbits(32) for _ in range(3)]


def _g54a710(c):
    e = c.emu
    self_o = _rnd(c, 0xa300)
    if c.rng.random() < 0.3:
        e.w32(self_o + 0xa269, 0)
    _hook(c, 0x634273, 2, 0, lecx=False)
    _hook(c, 0x54de40, 0, 0)
    return [self_o]


def _g638690(c):
    _hook(c, 0x638610, 0, 0)
    return [_obj(c, 0x40, _vt(c, 'o', 10, {0x1c: (0, 0, True), 0x20: (0, 0, True)}))]


def _g4b0c50(c):
    self_o = _rnd(c, 0x60)
    sg = _obj(c, 0x20, _vt(c, 'sg', 30, {0x44: (1, 4, True), 0x54: (1, 4, True)}))
    return [self_o, sg]


def _g54f0d0(c):
    e = c.emu
    self_o = _rnd(c, 0x20)
    if c.rng.random() < 0.2:
        e.w32(self_o + 4, 0)
        return [self_o, c.rng.getrandbits(32)]
    hr = c.rng.choice([0, 1, 0x80004005, 0x7fffffff, 0x80000000, c.rng.getrandbits(32)])

    def h(e, r):
        a = [e.arg32(k) for k in range(7)]
        e.calllog.append(('dev', 0x10, a[0], a[1], a[2], a[3], a[4], e.r32(a[5]), a[6]))   # a[5] is a stack address
        e.ret(eax=hr, argbytes=28)
    dev = _obj(c, 0x20, e.fake_vtable('dev', 8, {0x10: h}))
    e.w32(self_o + 4, dev)
    return [self_o, c.rng.getrandbits(32)]


def _g4afd50(c):
    e = c.emu
    self_o = _rnd(c, 0x80)
    cmd = c.rng.getrandbits(32)
    if c.rng.random() < 0.7:
        e.w16(self_o + 0x66, cmd & 0xffff)
    data = _rnd(c, 0x10)
    rv = c.rng.choice([0, 0, 1, 0xffffffff])

    def h(e, r):
        e.calllog.append(('stricmp', e.arg32(0), e.arg32(1)))
        e.ret(eax=rv, argbytes=0)
    e.stub_import('_stricmp', h)
    return [self_o, cmd, data]


def _g561f50(c):
    e = c.emu
    r = _obj(c, 0x20, _vt(c, 'r', 50, {0xa4: (2, 0, True)}))
    eng = _obj(c, 0x20, e.fake_vtable('eng', 50, {0xbc: (lambda e, _: (e.calllog.append(('eng', 0xbc, e.reg('ecx'))), e.ret(eax=r)))}))
    e.w32(0x70039c, eng)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32)]


N = 'fresh 17 batch 1'
S(0x54c3d0, 'GUESS FUN_54c3d0', 'thiscall', None, ret='eax', gen=_g54c3d0, note=N + '; COM slot +0x48 of this+0x63ec, tail 0x54ab70 (hooked GUESS)')
S(0x650b50, 'ZRenderBaseDll::PushScene(const char*)', 'thiscall', None, ret='eax', gen=_g650b50, note=N)
S(0x64f9d0, 'ZRender::DrawMemory()', 'thiscall', None, ret='eax', gen=_g64f9d0, note=N)
S(0x657450, 'ZPrimControlGC::GetPrimSplineIndices(unsigned int)', 'thiscall', None, ret='eax', gen=_g657450, note=N)
S(0x57aa50, 'ZFFMissingControllerDialog::OnWindowClose(unsigned int, bool)', 'thiscall', None, ret='al', gen=_g57aa50, note=N + '; base 0x562e90 hooked')
S(0x650dd0, 'ZRender::SetCameraList(LINKSORTREFTAB*)', 'thiscall', None, ret='eax', gen=_g650dd0, note=N)
S(0x4d5410, 'IOFSMemoryAccess_t::nativeWrite(void*, unsigned int, ImpNativeFd_t*)', 'stdcall', None, ret='eax', gen=_glog, note=N)
S(0x4d7710, 'FsZip_t::write(IOFSHandle_t*, void*, unsigned int)', 'stdcall', None, ret='eax', gen=_glog, note=N)
S(0x54a710, 'GUESS FUN_54a710', 'thiscall', None, ret='eax', gen=_g54a710, note=N + '; delete 0x634273 and tail 0x54de40 hooked')
S(0x638690, 'GUESS FUN_638690', 'thiscall', None, ret='eax', gen=_g638690, note=N + '; 0x638610 hooked')
S(0x4b0c50, 'CCutSequenceSoundEnvironment::Save(ZSaveGame*)', 'thiscall', None, ret='al', gen=_g4b0c50, note=N)
S(0x54f0d0, 'GUESS FUN_54f0d0', 'thiscall', None, ret='al', gen=_g54f0d0, note=N + '; COM slot +0x10, 7 words')
S(0x4afd50, 'CCutSequenceInfo::Command(unsigned short, void*)', 'thiscall', None, ret='eax', gen=_g4afd50, note=N + '; _stricmp import stubbed')
S(0x561f50, 'GUESS FUN_561f50', 'cdecl', None, ret='eax', gen=_g561f50, note=N + '; naked tail jump, 2 pass-through words')
