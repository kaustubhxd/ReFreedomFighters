"""specs_s234.py - ladder thread batch 234: ZLNKWHANDS folded stubs, destructor, CopyDataBlock, Load, Save."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import ladder_kit as K


def _assert(c, p=0.85):
    e = c.emu
    if c.rng.random() < p:
        def ah(e2, res_):
            e2.calllog.append(('assert',))
            e2.ret()
        e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    else:
        e.w32(0x7003b0, 0)


def _hooks(c, table):
    """table: [(addr, name, nargs, eax_fn or None)] -> logging stand-ins (this, stack args)."""
    e = c.emu
    for addr, name, n, fn in table:
        def mk(name=name, n=n, fn=fn):
            def h(e2, res_):
                a = [e2.arg32(i) for i in range(n)]
                e2.calllog.append((name, e2.reg('ecx'), tuple(K.nostack(x) for x in a)))
                eax = fn(e2, a) if fn else 0x5a5a
                e2.ret(eax=eax, argbytes=0 if name.startswith('cdecl') else 4 * n)
            return h
        e.hook(addr, mk())


def _plain(c):
    _assert(c)
    return []


def _this(c, nargs):
    _assert(c)
    s = K.rnd(c, 0x80)
    return [s] + [c.rng.getrandbits(32) for _ in range(nargs)]


def _pack(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x80)
    if r.random() < 0.3:
        e.w32(s + 0x60, 0)
    nm = r.getrandbits(32)
    _hooks(c, [(0x4e5330, 'ZAnimFilePack::GetAnimFileName', 0, lambda e2, a: nm)])
    return [s]


def _dtor(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x400)
    if r.random() < 0.3:
        e.w32(s + 0x3b7, 0)
    else:
        rt = K.rnd(c, 0x20)
        e.w32(rt, K.vt(c, 'reftab', {0: (1, lambda e2, a: (0, None, None))}, nslots=8))
        e.w32(s + 0x3b7, rt)
    _hooks(c, [(0x468080, 'ZCTRLIKLNKOBJ dtor 0x468080', 0, None), (0x4690b0, 'cdecl 0x4690b0', 2, None),
               (0x45c510, 'cdecl ZGEOM::operator delete', 1, None)])
    return [s, r.getrandbits(32) & r.choice([0xffffffff, 7, 5, 1, 4, 0])]


def _cdb(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x100)
    d = K.rnd(c, 0x40)
    types = [r.choice([3, 3, 4, 4, 0x103, 0x204, 1]) for _ in range(2)]
    st = {'i': 0}

    def gt(e2, a):
        v = types[st['i'] % 2]
        st['i'] += 1
        return v | 0x77700
    v = r.getrandbits(32)

    def get1(e2, a):
        e2.w32(a[0], 0x1234)
        return 0

    def gets(e2, a):
        e2.w32(a[0], v)
        return 0
    _hooks(c, [(0x4681a0, 'ZCTRLIKLNKOBJ::CopyDataBlock', 1, None), (0x4e1600, 'DBLK::GetType', 0, gt),
               (0x4e11e0, 'DBLK::Get(int*,int)', 2, get1), (0x4e1440, 'DBLK::Get(char**)', 1, gets),
               (0x4e1b30, 'DBLK::NextBlock', 0, None)])
    return [s, d]


def _emb(c, s, slot):
    e = c.emu
    for off in (0x34f, 0x2e7):
        e.w32(s + off, K.vt(c, 'emb%x' % off, {slot: (2, lambda e2, a: (0, None, None))}, nslots=4))


def _load(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x400)
    _emb(c, s, 4)
    st = K.rnd(c, 0x10)
    zero = r.random() < 0.4

    def rd(e2, a):
        n = a[1]
        if n == 4:
            e2.w32(a[0], 0 if zero else r.getrandbits(32))
        else:
            e2.wbytes(a[0], bytes(r.getrandbits(8) for _ in range(n)))
        return 0, None, None

    def rdf(e2, a):
        e2.w32(a[0], r.getrandbits(32))
        return 0, None, None
    e.w32(st, K.vt(c, 'loadgame', {0x18: (2, rd), 0x28: (1, lambda e2, a: (0, None, None)), 0x50: (1, rdf)}, nslots=0x20))
    mem = K.rnd(c, 0x20) if r.random() < 0.85 else 0
    _hooks(c, [(0x468220, 'ZCTRLIKLNKOBJ::Load', 1, None), (0x466eb0, 'ZTARGET::Load', 2, None),
               (0x41e290, 'cdecl __builtin_new', 1, lambda e2, a: mem),
               (0x4ccbe0, 'REFTAB::REFTAB', 2, lambda e2, a: e2.reg('ecx'))])
    return [s, st]


def _save(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x400)
    _emb(c, s, 0)
    st = K.rnd(c, 0x10)

    def wr(e2, a):
        return 0, None, e2.rbytes(a[0], a[1])
    e.w32(st, K.vt(c, 'savegame', {0x10: (2, wr), 0x20: (1, lambda e2, a: (0, None, None)),
                                   0x4c: (1, lambda e2, a: (0, None, None))}, nslots=0x20))
    if r.random() < 0.25:
        e.w32(s + 0x3b7, 0)
    else:
        rt = K.rnd(c, 0x20)
        vals = [r.getrandbits(32) if r.random() < 0.7 else 0 for _ in range(2)]
        i = {'n': 0}

        def cnt(e2, a):
            v = vals[i['n'] % 2]
            i['n'] += 1
            return v, None, None
        e.w32(rt, K.vt(c, 'reftab', {0x14: (0, cnt)}, nslots=8))
        e.w32(s + 0x3b7, rt)
    _hooks(c, [(0x468270, 'ZCTRLIKLNKOBJ::Save', 1, None), (0x467850, 'ZTARGET::Save', 2, None)])
    return [s, st]


S(0x4d50c0, 'folded assert stub (ZLNKWHANDS::CallBackItemAction/GetNearItems, low)', 'cdecl', None, ret=None,
  gen=_plain, note='batch234')
S(0x510bd0, 'folded assert stub ret 8 (ZLNKWHANDS::ControlUseTwo, low)', 'thiscall', None, ret=None,
  gen=lambda c: _this(c, 2), note='batch234')
S(0x6368b0, 'folded assert stub ret 4 (ZLNKWHANDS::ControlUseOneExtra, low)', 'thiscall', None, ret=None,
  gen=lambda c: _this(c, 1), note='batch234')
S(0x54c2c0, 'folded return true ret 4 (ZLNKWHANDS::ShowChamberAnim/ShowReloadAnim, low)', 'thiscall', None, ret='al',
  gen=lambda c: _this(c, 1), note='batch234')
S(0x610420, 'folded empty ret 0x10 (ZLNKWHANDS::ModifyPickupAction, low)', 'thiscall', None, ret=None,
  gen=lambda c: _this(c, 4), note='batch234')
S(0x4632a0, 'anim file name getter (+0x60 pack) (name map low)', 'thiscall', None, ret='eax', gen=_pack, note='batch234')
S(0x471f90, 'ZLNKWHANDS::~ZLNKWHANDS (scalar deleting)', 'thiscall', None, ret='eax', gen=_dtor, note='batch234')
S(0x473370, 'ZLNKWHANDS::CopyDataBlock', 'thiscall', None, ret=None, gen=_cdb, note='batch234')
S(0x474770, 'ZLNKWHANDS::Load', 'thiscall', None, ret='al', gen=_load, note='batch234')
S(0x4753c0, 'ZLNKWHANDS::Save', 'thiscall', None, ret='al', gen=_save, note='batch234')
