"""specs_s1501.py - recruits thread batch 1501: ZGameOSD squad orders (recruit, defend, form, attack, scout).
Every direct callee outside the function under test is a recorder hook (recruits_util.hook_rec): PlayCommandAnim,
PlaySound_Command (random return), CommandAll/OneRecruit, FindNextRecruit (sequence of ids, then 0; its output
pointer is recorded only as null / not null), AddRecruit (optionally bumps the recruited count, so the loop in
RecruitAll ends either way), PurgeOneWoundedIfFull, ZFFActor::PlaySound_Command, CommandPointerAtEnemy and the
order wrappers under the key handlers. Vtable slots are Python recorders (pystub); pointers to the caller's
stack are recorded by content."""
import struct
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _hero(c):
    r = c.rng
    return obj(c, 0x100, {0x84: pystub(c, 1, deref={0: 3}),
                          0x128: pystub(c, 3),
                          0x12c: pystub(c, 3, deref={2: 2})})


def _sys(c, table_slots=None, rand=None):
    r = c.rng
    sysobj = rnd(c, 0x200)
    val = c.emu.alloc(4, 4)
    c.emu.wf32(val, r.random() if rand is None else rand)
    code = c.emu.alloc(16, 16)
    c.emu.wbytes(code, b'\xd9\x05' + struct.pack('<I', val) + b'\xc2\x08\x00')   # fld dword [val]; ret 8
    vt = c.emu.alloc(0x200, 4)
    c.emu.w32(vt + 0x1c0, code)
    c.emu.w32(sysobj, vt)
    tab = obj(c, 0x20, table_slots or {})
    c.emu.w32(sysobj + 0x9b, tab)
    c.emu.w32(0x70039c, sysobj)
    c.emu.mu.ctl_flush_tb()
    return sysobj


def _osd(c):
    r = c.rng
    s = rnd(c, 0x2400)
    c.emu.w32(s + 0x1d0b, _hero(c))
    hook_rec(c, 0x593f40, 1, this=True)
    snd = r.getrandbits(32)
    hook_rec(c, 0x594040, 2, ret=lambda e, k: (snd + k) & 0xffffffff, this=True)
    hook_rec(c, 0x596d70, 2, this=True)
    hook_rec(c, 0x596ef0, 2, this=True)
    return s


def _order(c):
    clear_hooks(c)
    s = _osd(c)
    r = c.rng
    rand = r.choice([r.random(), 0.5, float('nan'), r.uniform(0.49, 0.51)])
    _sys(c, rand=rand)
    return [s]


def _wrap(callees):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        s = rnd(c, 0x2400)
        for a in callees:
            hook_rec(c, a, 0, this=True)
        hook_rec(c, 0x5cda40, 0, ret=r.choice([0, 1, r.getrandbits(32), 0x100]), this=True)
        c.emu.w32(s + 0x44, obj(c, 0x20, {0x12c: pystub(c, 3)}))
        c.emu.w32(s + 0x22df, 0 if r.random() < 0.3 else r.getrandbits(32))
        b = r.getrandbits(32)
        if r.random() < 0.3:
            b &= 0xffffff00
        return [s, b]
    return gen


def _find_current(c):
    clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x2400)
    n = r.randint(1, 10) if r.random() < 0.95 else 0
    actors = {}
    ids = []
    for i in range(n):
        a = obj(c, 0x800, {0x670: pystub(c, 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
        c.emu.w32(a + 0x77f, 5 if r.random() < 0.3 else r.randint(0, 8))
        idv = r.getrandbits(32)
        actors[idv] = a
        ids.append(idv)
        c.emu.w32(s + 0x1dae + 4 * i, idv)
    c.emu.w32(s + 0x1dae - 4, 0)   # ids[-1] for an empty list
    c.emu.w32(s + 0x1fae, n)

    def h(emu, res):
        emu.ret(actors.get(emu.arg32(0), 0), 4)
    _sys(c, {0x58: c.emu.stub_fn('id->actor', h)})
    start = r.choice([r.randint(-3, n + 2), r.getrandbits(32)])
    # steps other than -1, 0, 1 can cycle without meeting the start again, which loops forever in the original too
    step = r.choice([1, -1, 0, 1, -1])
    return [s, start & 0xffffffff, step & 0xffffffff]


def _recruit_common(c):
    r = c.rng
    s = rnd(c, 0x2400)
    c.emu.w32(s + 0x1d0b, _hero(c))
    snd = r.getrandbits(32)
    hook_rec(c, 0x594040, 2, ret=snd, this=True)
    ids = [r.getrandbits(32) | 1 for _ in range(r.randint(0, 5))] + [0]
    hook_rec(c, 0x597720, 1, ret=lambda e, k: ids[min(k, len(ids) - 1)], this=True, nullflag=(0,))
    bump = r.random() < 0.5

    def add_side(e, k):
        if bump:
            e.w32(s + 0x1fae, e.r32(s + 0x1fae) + 1)
    hook_rec(c, 0x5967b0, 1, this=True, side=add_side)
    hook_rec(c, 0x597b50, 0, this=True)
    hook_rec(c, 0x5a1ac0, 3, this=True)
    actor = rnd(c, 0x40) if r.random() < 0.8 else 0
    hid = r.getrandbits(32)
    _sys(c, {0x4c: pystub(c, 1, ret=hid), 0x58: pystub(c, 1, ret=actor)})
    n = r.randint(0, 6)
    c.emu.w32(s + 0x1fae, n)
    c.emu.w32(s + 0x1fba, r.choice([n, n + 1, n + 3, max(n - 1, 0), r.getrandbits(32)]))
    c.emu.w32(s + 0x4f7, 0 if r.random() < 0.15 else 1)
    return s


def _recruit_all(c):
    clear_hooks(c)
    return [_recruit_common(c)]


def _recruit_one(c):
    clear_hooks(c)
    return [_recruit_common(c)]


S(0x597640, 'ZGameOSD defend all (0x597640)', 'thiscall', gen=_order, note='batch1501')
S(0x597f70, 'ZGameOSD defend one (0x597f70)', 'thiscall', gen=_order, note='batch1501')
S(0x597930, 'ZGameOSD form all (0x597930)', 'thiscall', gen=_order, note='batch1501')
S(0x597980, 'ZGameOSD form one (0x597980)', 'thiscall', gen=_order, note='batch1501')
S(0x5968c0, 'ZGameOSD::AttackTargetAll', 'thiscall', gen=_order, note='batch1501')
S(0x596900, 'ZGameOSD::AttackTargetOne', 'thiscall', gen=_order, note='batch1501')
S(0x597e90, 'ZGameOSD::ScoutAheadAll', 'thiscall', gen=_order, note='batch1501')
S(0x597f00, 'ZGameOSD::ScoutAheadOne', 'thiscall', gen=_order, note='batch1501')
S(0x59a7e0, 'ZGameOSD::RecruitFollow', 'thiscall', gen=_wrap([0x597c40, 0x597d30]), note='batch1501')
S(0x59a7a0, 'ZGameOSD::RecruitDefend', 'thiscall', gen=_wrap([0x597640, 0x597f70]), note='batch1501')
S(0x59a800, 'ZGameOSD::RecruitForm', 'thiscall', gen=_wrap([0x597930, 0x597980]), note='batch1501')
S(0x59a720, 'ZGameOSD::RecruitAttack', 'thiscall', gen=_wrap([0x5968c0, 0x596900, 0x597e90, 0x597f00]), note='batch1501')
S(0x597680, 'ZGameOSD::FindCurrentRecruit', 'thiscall', ret='eax', gen=_find_current, note='batch1501')
S(0x597c40, 'ZGameOSD::RecruitAll', 'thiscall', gen=_recruit_all, note='batch1501')
S(0x597d30, 'ZGameOSD::RecruitOne', 'thiscall', gen=_recruit_one, note='batch1501')
