"""specs_f0505.py - fresh slice 17, batch 5."""
from pilot import S
from specs_f0101 import _rnd, _vt, _hook, _obj
from specs_f0202 import _assert_hook


def _factory(ctor):
    def g(c):
        e = c.emu
        blk = 0 if c.rng.random() < 0.25 else _rnd(c, 0x40)
        al = _obj(c, 0x10, e.fake_vtable('alloc', 0x20, {0x44: (lambda e, r: (e.calllog.append(('alloc', e.reg('ecx'), e.arg32(0))), e.ret(eax=blk, argbytes=4)))}))
        db = _rnd(c, 0x20)
        e.w32(db + 8, al)
        eng = _rnd(c, 0x100)
        e.w32(eng + 0x9b, db)
        e.w32(0x70039c, eng)
        _hook(c, ctor, 0, 0)
        return [c.rng.getrandbits(32)]
    return g


def _g4ce110(c):
    e = c.emu
    if c.rng.random() < 0.1:
        return [0, _rnd(c, 8)]
    ents = [_rnd(c, 8) for _ in range(c.rng.randint(0, 5))]
    hit = c.rng.randrange(len(ents) + 1)
    seq = list(ents)

    def s4c(e, r):
        p = e.arg32(0)
        e.w32(p, 0x1234); e.w32(p + 4, 0x5678); e.w32(p + 8, 0x9abc)
        e.calllog.append(('t4c', e.reg('ecx')))
        e.ret(eax=c.rng.getrandbits(32), argbytes=4)

    def s64(e, r):
        p = e.arg32(0)
        w = (e.r32(p), e.r32(p + 4), e.r32(p + 8))
        v = seq.pop(0) if seq else 0
        e.w32(p, e.r32(p) + 1)
        e.calllog.append(('t64', e.reg('ecx'), w, v))
        e.ret(eax=v, argbytes=4)

    def cmp(e, r):
        a, b = e.arg32(0), e.arg32(1)
        e.calllog.append(('stricmp', a, b))
        e.ret(eax=0 if (len(ents) > hit and a == e.r32(ents[hit])) else c.rng.choice([1, -1 & 0xffffffff, 0x100]))
    e.stub_import('_stricmp', cmp)
    tab = _obj(c, 0x10, e.fake_vtable('tab', 0x20, {0x4c: s4c, 0x64: s64}))
    return [tab, _rnd(c, 8)]


def _g6058d0(c):
    e = c.emu
    _assert_hook(c)
    slots = [_rnd(c, 8), _rnd(c, 8)]
    for s in slots:
        e.w8(s + 4, c.rng.choice([4, 4, 0, 1]))
        e.w32(s, _obj(c, 0x10, _vt(c, 'o', 12, {0x24: (0, 0, True), 0x28: (0, 0, True)})))
    same = c.rng.random() < 0.2
    pick = {}
    arr1, arr2 = _rnd(c, 8), _rnd(c, 8)
    pick[arr1] = slots[0]
    pick[arr2] = slots[0] if same else slots[1]

    def get(e, r):
        a = e.reg('ecx')
        e.calllog.append(('get', a, e.arg32(0)))
        e.ret(eax=pick.get(a, 0), argbytes=4)
    e.hook(0x5003d0, get)
    arg = _rnd(c, 0x10)
    e.w32(arg + 4, arr1)
    e.w32(arg + 8, arr2)
    return [_rnd(c, 8), arg]


def _g5bfa10(c):
    e = c.emu
    rd = _rnd(c, 0x10)
    for a, nm in ((0x4e5e60, 'u32'), (0x4e5e40, 'u16')):
        def h(e, r, nm=nm):
            v = c.rng.getrandbits(32)
            e.calllog.append((nm, e.reg('ecx'), v))
            e.ret(eax=v)
        e.hook(a, h)
    return [_rnd(c, 0x80), rd]


def _g4488d0(c):
    e = c.emu
    blk = _rnd(c, 0x10)
    t = c.rng.choice([1, 1, 0, 2, 0x101])
    _hook(c, 0x448a30, 1, 4)
    e.hook(0x4e1600, lambda e, r: (e.calllog.append(('type', e.reg('ecx'))), e.ret(eax=t)))
    _hook(c, 0x4e1b30, 0, 0)

    def getf(e, r):
        p = e.arg32(0)
        e.calllog.append(('getf', e.reg('ecx'), e.arg32(1)))      # p is a stack address: not logged
        e.w32(p, c.rng.getrandbits(32))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    e.hook(0x4e12f0, getf)

    def getu(e, r):
        p = e.arg32(0)
        e.calllog.append(('getu', e.reg('ecx'), p, e.arg32(1)))
        e.w32(p, c.rng.getrandbits(32))
        e.ret(eax=c.rng.getrandbits(32), argbytes=8)
    e.hook(0x4e12e0, getu)
    return [_rnd(c, 0x30), blk]


def _g648810(c):
    e = c.emu
    self_o = _rnd(c, 0x90)
    n = c.rng.choice([0, 1, 2, 5, 15, 16, c.rng.randint(0, 15)])
    e.w32(self_o, n)
    keys = sorted((c.rng.randint(-50, 50) for _ in range(n)), reverse=True)
    for i, k in enumerate(keys):
        e.w32(self_o + 0x44 + 4 * i, k & 0xffffffff)
    key = c.rng.choice([c.rng.randint(-60, 60)] + (keys[:1] if keys else [0]))
    if n == 16:
        _assert_hook(c)
    pv = _rnd(c, 4)
    return [self_o, pv, key & 0xffffffff]


N = 'fresh 17 batch 5'
S(0x578890, 'GUESS FUN_578890 (factory, ctor 0x578560)', 'fastcall', None, ret='eax', gen=_factory(0x578560), note=N + '; ECX passed to allocator slot +0x44; ctor hooked; SEH frame not reproduced')
S(0x57a550, 'GUESS FUN_57a550 (factory, ctor 0x57a440)', 'fastcall', None, ret='eax', gen=_factory(0x57a440), note=N + '; same shape')
S(0x57cad0, 'GUESS FUN_57cad0 (factory, ctor 0x57c7c0)', 'fastcall', None, ret='eax', gen=_factory(0x57c7c0), note=N + '; same shape')
S(0x5c0f50, 'GUESS FUN_5c0f50 (CEnemyFlag factory)', 'fastcall', None, ret='eax', gen=_factory(0x5c0a60), note=N + '; same shape')
S(0x4ce110, 'STRREFTAB::FindStr(const char*)', 'thiscall', None, ret='eax', gen=_g4ce110, note=N + '; _stricmp stubbed; iterator logged by value')
S(0x6058d0, 'GUESS FUN_6058d0 (slot assign)', 'thiscall', None, ret=None, gen=_g6058d0, note=N + '; 0x5003d0 hooked; EAX incidental (not compared)')
S(0x5bfa10, 'CLogicOperatorEvaluatorTriggerFunctions::ReadInput(DBREAD&)', 'thiscall', None, ret=None, gen=_g5bfa10, note=N + '; DBREAD u32/u16 readers hooked')
S(0x4488d0, 'ZGateLightSpot::CopyDataBlock(DBLK*)', 'thiscall', None, ret=None, gen=_g4488d0, note=N + '; ZLIGHT::CopyDataBlock and DBLK helpers hooked')
S(0x648810, 'GUESS FUN_648810 (sorted insert, 16 pairs)', 'thiscall', None, ret='eax', gen=_g648810, note=N)
