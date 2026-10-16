"""specs_f1005.py - fresh-10 batch 5: scene-factory creators, particle/script/menu helpers (slice 10)."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
from h10 import L, obj, rbuf, patch, iat, log_obj


def R(c): return c.rng.getrandbits(32)
def fbits(c): return struct.unpack('<I', struct.pack('<f', c.fv()))[0]


def _factory(ctor):
    def g(c):
        patch(c, ctor, L('ctor', 0, ret=R(c)))
        f = obj(c, 'fac', {0x44: L('fac44', 1, ret=c.rng.choice([0, rbuf(c, 0x220)]))}, size=0x10)
        s = rbuf(c, 0x20); c.emu.w32(s + 8, f); rm = rbuf(c, 0x100); c.emu.w32(rm + 0x9b, s); c.emu.w32(0x70039c, rm)
        return [rbuf(c, 0x10)]
    return g
for a, ct, nm in ((0x4cad60, 0x4ca8f0, 'GUESS create + 0x4ca8f0'), (0x56ca20, 0x56c810, 'GUESS create + 0x56c810'),
                  (0x5b2b60, 0x5b2550, 'GUESS create ZActionControlMap'), (0x5bfd60, 0x5bfac0, 'GUESS create CEntityTracker'),
                  (0x577920, 0x573590, 'GUESS create + 0x573590, vtable 0x6a9768')):
    S(a, nm, 'thiscall', None, ret='eax', gen=_factory(ct))


def g_615ee0(c):   # GUESS: PrimInstanceCreate(e), then fill e+0x20..+0x2c; returns true
    patch(c, 0x64d400, L('PrimInstanceCreate', 1, ret=R(c)))
    e = rbuf(c, 0x40); a = rbuf(c, 0x20); b = rbuf(c, 0x20); d = rbuf(c, 0x10); s = rbuf(c, 0x30)
    c.emu.w32(e + 8, a); c.emu.w32(a + 0x10, b); c.emu.w32(b + 8, d); c.emu.w32(e + 0x14, s)
    if c.rng.random() < 0.4: c.emu.w32(s + 0xc, 0)
    if c.rng.random() < 0.4: c.emu.w32(e + 0xc, 0)
    return [rbuf(c, 0x10), e]
S(0x615ee0, 'GUESS prim instance setup', 'thiscall', None, ret='al', gen=g_615ee0)


def g_456e60(c):   # ZParticleController::RegisterParticleTemplate(unsigned)
    log_obj(c, 1)
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))
    o = rbuf(c, 0x1d + 0x800 + 0x20)
    ids = [c.rng.randint(1, 40) for _ in range(256)]
    if c.rng.random() < 0.7: ids[c.rng.randint(0, 255)] = 0
    for i, v in enumerate(ids): c.emu.w32(o + 0x1d + 8 * i, v)
    return [o, c.rng.choice([c.rng.randint(1, 40), 0, R(c)])]
S(0x456e60, 'ZParticleController::RegisterParticleTemplate', 'thiscall', None, ret='eax', gen=g_456e60)


def g_5f51e0(c):   # GUESS push of a tagged value (tag 4 = refcounted object: slot 0x28 release, slot 0x24 addref)
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ecx=False)))
    def tv(p):
        t = c.rng.choice([4, 4, 1, 2, R(c) & 0xff]); c.emu.w8(p + 4, t)
        c.emu.w32(p, obj(c, 'rc', {0x24: L('addref', 0, ret=R(c)), 0x28: L('release', 0, ret=R(c))}, size=0x10) if t == 4 else R(c))
    arr = rbuf(c, 0x80)
    n = c.rng.randint(0, 8); cap = c.rng.choice([n + 1, n + 3, n, max(n - 1, 0)])
    for i in range(10): tv(arr + 8 * i)
    o = rbuf(c, 0x10); c.emu.w32(o, arr); c.emu.w32(o + 4, cap); c.emu.w32(o + 8, n)
    src = arr + 8 * n if c.rng.random() < 0.15 else rbuf(c, 0x10)
    if src != arr + 8 * n: tv(src)
    return [o, src]
S(0x5f51e0, 'GUESS tagged value push', 'thiscall', None, ret='eax', gen=g_5f51e0)


def g_56fc20(c):   # CNewMenu::Sub()
    patch(c, 0x56fb10, L('SetCaretPos', 0, ret=R(c)))
    o = rbuf(c, 0x600)
    ln = c.rng.randint(0, 20)
    for i in range(ln): c.emu.w8(o + 0x1c9 + i, c.rng.randint(1, 255))
    c.emu.w8(o + 0x1c9 + ln, 0)
    n = c.rng.choice([0, c.rng.randint(1, 8)]); c.emu.w32(o + 0x4b2, n)
    for i in range(8): c.emu.w32(o + 0x3b2 + 4 * i, c.rng.randint(0, ln))
    c.emu.w32(o + 0x5ce, obj(c, 'edit', {0x284: L('edit284', 1)}, size=0x10))
    c.emu.w32(o + 0x5ca, obj(c, 'snd', {0x248: L('snd248', 1)}, size=0x10))
    return [o]
S(0x56fc20, 'CNewMenu::Sub', 'thiscall', None, ret=None, gen=g_56fc20)


def g_4d4c20(c):   # IOFSPhysicalAccess_t::nativeEof(ImpNativeFd_t*) (low): feof(fd), hook if ferror(fd)
    iat(c, 0x6763dc, 'feof', 1, R(c), pop=0); iat(c, 0x6763d8, 'ferror', 1, c.rng.choice([0, 0, 1, R(c)]), pop=0)
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert', L('assert', 0, ret=R(c), ecx=False)))
    return [rbuf(c, 0x10), rbuf(c, 0x10)]
S(0x4d4c20, 'IOFSPhysicalAccess_t::nativeEof', 'thiscall', None, ret='eax', gen=g_4d4c20)


def _vsprintf(e, r):
    buf, fmt, va = e.arg32(0), e.arg32(1), e.arg32(2)
    e.calllog.append(('vsprintf', 0, (fmt, va)))
    e.wbytes(buf, b'plot\x00' + struct.pack('<I', fmt ^ e.r32(va)))
    e.ret(eax=9, argbytes=0)


def g_4246e0(c):   # ZSysInterfaceGC::UPlotF(ZRender*, int, int, const char*, ...) (cdecl, this first)
    rm = rbuf(c, 0xa00); c.emu.w32(0x70039c, rm)
    c.emu.w32(rm + 0x9c7, c.rng.choice([0, 0x80000000, fbits(c), 0x7fc00000]))
    patch(c, 0x42abee, _vsprintf)
    rd = obj(c, 'render', {0x124: L('render124', 4, pop=0, ecx=False)}, size=0x10)
    return [rbuf(c, 0x10), rd, R(c), R(c), R(c), R(c), R(c)]
S(0x4246e0, 'ZSysInterfaceGC::UPlotF', 'cdecl', None, ret=None, gen=g_4246e0, stack_arg_bytes=12)


def g_63eca0(c):   # GUESS: collect element ids (+0x38) of a chunked list into out[]; returns the count
    nch = c.rng.randint(1, 3); chunks = []
    for k in range(nch):
        cnt = c.rng.randint(1, 5); ch = rbuf(c, 0x10 + 4 * cnt); c.emu.w32(ch, cnt)
        for i in range(cnt): c.emu.w32(ch + 0x10 + 4 * i, rbuf(c, 0x40))
        chunks.append((ch, cnt))
    for k, (ch, cnt) in enumerate(chunks): c.emu.w32(ch + 8, chunks[k + 1][0] if k + 1 < nch else 0)
    ch0, cnt0 = chunks[0]; i0 = c.rng.randint(0, cnt0 - 1)
    it = rbuf(c, 0x10)
    c.emu.w32(it, 0 if c.rng.random() < 0.15 else ch0 + 0x10 + 4 * i0); c.emu.w32(it + 4, i0); c.emu.w32(it + 8, ch0)
    o = rbuf(c, 0x200); c.emu.w32(o + 0x1c8, c.emu.fake_vtable('list', 4, {0xc: L('begin', 1, ret=it)}))
    return [o, rbuf(c, 0x80)]
S(0x63eca0, 'GUESS chunked list collect +0x38', 'thiscall', None, ret='eax', gen=g_63eca0)


def g_42d2e0(c):   # ZSysInterface::HandleIfDef(string*&): push (slot8c(arg) && top) as a dword onto the if-stack
    def grow(e, r):
        e.calllog.append(('grow', e.reg('ecx'), (e.arg32(0), e.r32(e.arg32(1)))))
        e.ret(eax=0, argbytes=8)
    patch(c, 0x4301c0, grow)
    st = rbuf(c, 0x40); v = rbuf(c, 0x10)
    end = st + 4 * c.rng.randint(1, 8)
    c.emu.w32(end - 4, c.rng.choice([0, 1, R(c)])); c.emu.w32(v + 4, end); c.emu.w32(v + 8, c.rng.choice([end, end + 4, st + 0x40]))
    o = obj(c, 'sys', {0x8c: L('sys8c', 1, ret=c.rng.choice([0, 1, 0x100, R(c)]))}, size=0x1c00)
    c.emu.w32(o + 0x1b61, v)
    return [o, R(c)]
S(0x42d2e0, 'ZSysInterface::HandleIfDef', 'thiscall', None, ret=None, gen=g_42d2e0)


def g_551720(c):   # Signature_iff_EventTranslator_t::handleEventTranslation(factory, id, data) (low)
    patch(c, 0x5003d0, L('f5003d0', 1, retf=lambda e, a: 0x31000 + a[0]))
    patch(c, 0x5002f0, L('f5002f0', 1)); patch(c, 0x500360, L('f500360', 1))
    ev = obj(c, 'ev', {0x4c: L('ev4c', 0, ret=0x77000)}, size=0x10)
    fac = obj(c, 'fac', {0x18: L('fac18', 1, ret=c.rng.choice([0, ev]))}, size=0x10)
    d = rbuf(c, 0x10)
    for i in (1, 2): c.emu.w32(d + 4 * i, fbits(c))
    return [rbuf(c, 0x10), fac, R(c), d]
S(0x551720, 'Signature_iff_EventTranslator_t::handleEventTranslation', 'thiscall', None, ret='eax', gen=g_551720)
