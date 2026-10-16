"""specs_s804.py - animation layer thread, batch 804: SetDualFrame, ZBoneModifyBase::Update, UB clip getters."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, install_logger, vt_object, vslot


def _hdr(c):
    r = c.rng
    h = rnd(c, 0x80)
    for off in (0x60, 0x64):
        c.emu.w32(h + off, r.choice([r.randint(-50, 400), r.randint(0, 60), 0, r.getrandbits(32)]))
    return h


def _dual(c):
    only_hooks(c, {})
    mod = vt_object(c, 0x40, {0x18: vslot('mod.AddFrame', 5)}, name='mod')
    o = vt_object(c, 0x80, {0x288: vslot('GetAnimDeltaBones', 1, ret=lambda e, a: a[0] ^ 0x5555)}, name='lnk')
    c.emu.w32(o + 0x6c, mod)
    return [o, _hdr(c), F(c.fv(-1, 2)), _hdr(c), F(c.fv(-1, 2)), F(c.fv(0, 1)), F(c.fv(0, 1))]


def _update(c):
    e, r = c.emu, c.rng

    def rdmove(e, res):
        rd, mat, pos, dt = e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('Ragdoll.Move', rd, mat, pos, dt))
        e.ret(eax=r2, argbytes=12)

    def pose(e, res):
        rd, buf = e.reg('ecx'), e.arg32(0)
        e.calllog.append(('Ragdoll.Pose', rd))
        e.wbytes(buf, bytes((i * 37 + rd) & 0xff for i in range(0x1200)))
        e.ret(eax=0, argbytes=4)
    r2 = r.choice([0, 1, 0x100])
    only_hooks(c, {0x644af0: rdmove, 0x6421a0: pose, 0x641b60: logged_fn('DeactivateRagdoll', 1)})
    install_logger(c, nargs=2)   # after only_hooks (it restores the logger global); printf takes (sink, fmt) only
    g = rnd(c, 0x60)
    e.w32(0x70039c, g)
    fr = r.getrandbits(32)
    e.w32(g + 0x3c, fr)
    now = r.getrandbits(31)
    e.w32(g + 0x40, now)
    self = vt_object(c, 0x300, {0x28: vslot('bm.vt28', 1)}, name='bm')
    e.w32(self + 9, fr if r.random() < 0.15 else r.getrandbits(32))
    e.w32(self + 5, (now - r.randint(0, 5000)) & 0xffffffff)
    e.w32(self + 0x291, r.choice([0, r.getrandbits(32) | 1, r.getrandbits(32) | 1]))
    e.w8(self + 0x295, r.choice([0, 0, 0, 1]))

    def v284(e, res):
        buf, x = e.arg32(0), e.arg32(1)
        e.calllog.append(('obj.284', e.rbytes(buf, 0x1200)[::97], x))
        e.ret(eax=0, argbytes=8)
    obj = vt_object(c, 0x40, {0x2cc: vslot('obj.2cc', 0, ret=0x77), 0x284: v284}, name='obj')
    return [self, obj, rnd(c, 0x40), rnd(c, 0x20)]


def _item(c, wtype):
    r = c.rng
    tmpl = vt_object(c, 0x20, {0x330: vslot('tmpl.WeaponType', 0, ret=wtype)}, name='tmpl')
    return vt_object(c, 0x40, {0x1e0: vslot('item.IsDerivedFrom', 1, ret=r.choice([0, 1, 1, 0x100, 0x301])),
                               0x350: vslot('item.Template', 0, ret=tmpl)}, name='item')


def _wtype(c):
    r = c.rng
    return r.choice(list(range(14)) + [r.getrandbits(32)])


def _actor_ub(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    self = rnd(c, 0x800)
    e.w8(self + 0x726, r.choice([0, 1, 1, 2]))
    e.w32(self + 0x64c, r.choice([10, 10, 3, r.getrandbits(32)]))
    e.w8(self + 0x753, r.choice([0, 0, 0, 1]))
    e.w8(self + 0x26a, r.choice([0, 0, 1]))
    it = 0 if r.random() < 0.15 else _item(c, _wtype(c))
    return [self, it, r.getrandbits(32)]


def _ffactor_ub(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    self = vt_object(c, 0x800, {0x21c: vslot('GetAnim', 1, ret=0x4141)}, name='ffactor')
    e.w8(self + 0x7a6, r.getrandbits(8))
    e.w8(self + 0x726, r.choice([0, 1, 1]))
    e.w32(self + 0x64c, r.choice([10, 3]))
    e.w8(self + 0x753, r.choice([0, 0, 1]))
    e.w8(self + 0x26a, r.choice([0, 0, 1]))
    it = 0 if r.random() < 0.15 else _item(c, _wtype(c))
    return [self, it, r.getrandbits(32)]


def _hero(c):
    e, r = c.emu, c.rng
    it = 0 if r.random() < 0.15 else _item(c, _wtype(c))
    only_hooks(c, {0x5aeff0: logged_fn('InvInfo.GetFFItemType', 1, ret=r.choice([0x10, 0x10, 3, 0, 9]))})
    self = vt_object(c, 0x1000, {0x504: vslot('hero.HeldItem', 0, ret=it),
                                 0x438: vslot('hero.vt438', 0, ret=r.choice([0, 0, 0, 1, 0x200]))}, name='hero')
    e.w32(self + 0x417, r.choice([0, 2, 0x400, 0x402, 0x2000000, r.getrandbits(32)]))
    e.w8(self + 0x65c, r.choice([0, 1]))
    e.w32(self + 0x658, it if r.random() < 0.5 else r.getrandbits(32))
    return [self]


S(0x464650, 'ZLNKOBJ::SetDualFrame', 'thiscall', None, gen=_dual, note='batch804')
S(0x647610, 'ZBoneModifyBase::Update', 'thiscall', None, ret='al', gen=_update, note='batch804; ragdoll calls hooked')
S(0x478b70, 'ZActor::GetCurrentUBAnim', 'thiscall', None, ret='eax', gen=_actor_ub, note='batch804')
S(0x59fd00, 'ZFFActor::GetCurrentUBAnim', 'thiscall', None, ret='eax', gen=_ffactor_ub, note='batch804')
S(0x591b20, 'ZFFHERO::GetFFItemType', 'thiscall', None, ret='eax', gen=_hero, note='batch804')
S(0x5919f0, 'ZFFHERO::GetCurrentUBAnim', 'thiscall', None, ret='eax', gen=_hero, note='batch804')
