"""specs_s1500.py - recruits thread batch 1500: charisma meter, recruit list, squad and follower leaves.
Direct callees that are not part of a function under test are replaced by recorder hooks (recruits_util.hook_rec):
CSprite3D::Resize/ChangeObj, ZOnScreenDisplay::CharismaSet, SSquad::AddMember. SSquad::RemoveMember runs as exe code
under ZFFActor::RemoveFromSquad."""
from pilot import S
from recruits_util import rnd, stub, obj, hook_rec, clear_hooks


def _resize(c):
    clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x100)
    n = r.randint(0, 5)
    c.emu.w32(s + 0x3e, n)
    tab = c.emu.alloc(4 * max(n, 1), 4)
    w, h = r.randint(-50, 300), r.randint(-50, 300)
    for i in range(n):
        f = rnd(c, 0x30)
        if r.random() < 0.3:
            c.emu.w16(f + 0x28, w)
            c.emu.w16(f + 0x2a, h if r.random() < 0.7 else r.randint(0, 300))
        if r.random() < 0.1:
            c.emu.w16(f + 4, 0)
        c.emu.w32(tab + 4 * i, f)
    c.emu.w32(s + 0x62, tab)
    if r.random() < 0.2:
        c.emu.w32(s + 0x6e, w)
        c.emu.w32(s + 0x72, h if r.random() < 0.6 else h + 1)
    return [s, w, h]


def _charisma_set(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ec090, 2, this=True)
    s = rnd(c, 0x500)
    c.emu.w32(s + 0x47c, 12 if r.random() < 0.3 else r.randint(0, 11))
    v = r.choice([r.randint(0, 120), r.getrandbits(32), 100, 0])
    if r.random() < 0.3:
        c.emu.w32(s + 0x370, v if r.random() < 0.5 else 100)
    elif r.random() < 0.3:
        c.emu.w32(s + 0x370, 0)
    c.emu.w32(s + 0x43c, 0 if r.random() < 0.2 else rnd(c, 0x80))
    return [s, v]


def _osd12(c, s):
    for i in range(12):
        c.emu.w32(s + 0x440 + 4 * i, rnd(c, 0x40))


def _symbol_add(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5ebd80, 1, this=True)
    s = rnd(c, 0x600)
    _osd12(c, s)
    for k in range(8):
        c.emu.w32(s + 0x4b8 + 4 * k, rnd(c, 8))
    c.emu.w32(s + 0x47c, 12 if r.random() < 0.2 else r.randint(0, 11))
    return [s, r.randint(0, 7)]


def _symbol_clear(c):
    clear_hooks(c)
    s = rnd(c, 0x600)
    _osd12(c, s)
    return [s]


def _get_exp(c):
    clear_hooks(c)
    return [rnd(c, 0x2000)]


def _gameosd(c, osd_hook=True):
    r = c.rng
    if osd_hook:
        hook_rec(c, 0x5a5e90, 1, this=True)
    s = rnd(c, 0x2400)
    c.emu.w32(s + 0x1d0f, 0 if r.random() < 0.2 else rnd(c, 0x10))
    return s


def _set_exp(c):
    clear_hooks(c)
    s = _gameosd(c)
    return [s, c.rng.getrandbits(32)]


def _set_recruitable(c):
    clear_hooks(c)
    r = c.rng
    s = _gameosd(c)
    c.emu.w32(s + 0x1fbe, r.choice([r.randint(0, 12), r.getrandbits(32)]))
    return [s, r.choice([r.randint(-3, 15), r.getrandbits(32)])]


def _add_nonrecruitable(c):
    clear_hooks(c)
    r = c.rng
    s = _gameosd(c, False)
    c.emu.w32(s + 0x4ef, r.randint(0, 127))
    yes = r.getrandbits(24) << 8 | (0 if r.random() < 0.3 else r.randint(1, 255))
    o = obj(c, 0x40, {0x1e0: stub(c, 1, yes)})
    tab = obj(c, 0x20, {0x58: stub(c, 1, 0 if r.random() < 0.2 else o)})
    sysobj = rnd(c, 0x100)
    c.emu.w32(sysobj + 0x9b, tab)
    c.emu.w32(0x70039c, sysobj)
    return [s, r.getrandbits(32)]


def _remove_recruit(c):
    clear_hooks(c)
    r = c.rng
    s = rnd(c, 0x2000)
    n = r.choice([0, r.randint(1, 8), r.randint(1, 127)])
    ids = [r.randint(1, 12) for _ in range(n)]
    for i, v in enumerate(ids):
        c.emu.w32(s + 0x1dae + 4 * i, v)
    c.emu.w32(s + 0x1fae, n)
    c.emu.w32(s + 0x1fb2, r.randint(-2, n + 1) & 0xffffffff)
    return [s, r.randint(0, 13)]


def _get_osd(c):
    clear_hooks(c)
    base = rnd(c, 0x2c2d + 0x400)
    return [base + 0x200, c.rng.getrandbits(32)]


def _squad_by_index(c):
    clear_hooks(c)
    r = c.rng
    return [r.getrandbits(32), r.choice([-1, r.randint(0, 20), r.getrandbits(32)]) & 0xffffffff]


def _squad_index(c):
    clear_hooks(c)
    r = c.rng
    n = r.randint(0, 8)
    s = rnd(c, 0xd91 + 0xf4 * 9)
    c.emu.w32(s + 0xd8d, n)
    k = r.random()
    if k < 0.15:
        sq = 0
    elif k < 0.75 and n:
        sq = s + 0xd91 + 0xf4 * r.randint(0, n - 1)
    else:
        sq = s + 0xd91 + 0xf4 * r.randint(0, 9) + r.choice([0, 0, 4])
    return [s, sq]


def _squad(c, n=None):
    r = c.rng
    sq = rnd(c, 0xf4)
    n = r.randint(0, 16) if n is None else n
    c.emu.w32(sq, n)
    for i in range(n):
        c.emu.w32(sq + 4 + 4 * i, r.randint(1, 10))
    return sq


def _remove_member(c):
    clear_hooks(c)
    return [_squad(c), c.rng.randint(0, 11)]


def _actor_remove(c):
    clear_hooks(c)
    r = c.rng
    a = rnd(c, 0xa00)
    if r.random() < 0.2:
        c.emu.w32(a + 0x921, 0)
    else:
        sq = _squad(c)
        if r.random() < 0.6 and c.emu.r32(sq):
            c.emu.w32(sq + 4 + 4 * r.randint(0, c.emu.r32(sq) - 1), a)
        c.emu.w32(a + 0x921, sq)
    return [a]


def _actor_add(c):
    clear_hooks(c)
    r = c.rng
    ok = r.getrandbits(24) << 8 | (0 if r.random() < 0.4 else r.randint(1, 255))
    hook_rec(c, 0x5898c0, 1, ret=ok, this=True)
    return [rnd(c, 0xa00), rnd(c, 0xf4)]


def _get_follower(c):
    clear_hooks(c)
    r = c.rng
    h = rnd(c, 0xa1a + 0x30 * 13)
    c.emu.w32(h + 0xa16, r.choice([r.randint(0, 12), r.getrandbits(32)]))
    return [h, r.choice([r.randint(0, 13), r.getrandbits(32)])]


S(0x5ec090, 'CSprite3D::Resize', 'thiscall', gen=_resize, note='batch1500')
S(0x5a5e90, 'ZOnScreenDisplay::CharismaSet', 'thiscall', gen=_charisma_set, note='batch1500')
S(0x5a5f00, 'ZOnScreenDisplay::CharismaSymbolAdd', 'thiscall', gen=_symbol_add, note='batch1500')
S(0x5a5f40, 'ZOnScreenDisplay::CharismaSymbolClear', 'thiscall', gen=_symbol_clear, note='batch1500')
S(0x596ce0, 'ZGameOSD::CharismaGetExperience', 'thiscall', ret='eax', gen=_get_exp, note='batch1500')
S(0x596d00, 'ZGameOSD::CharismaSetExperience', 'thiscall', gen=_set_exp, note='batch1500')
S(0x596d30, 'ZGameOSD::CharismaSetRecruitable', 'thiscall', gen=_set_recruitable, note='batch1500')
S(0x596760, 'ZGameOSD::AddNonRecruitable', 'thiscall', gen=_add_nonrecruitable, note='batch1500')
S(0x597e00, 'ZGameOSD::RemoveRecruit', 'thiscall', gen=_remove_recruit, note='batch1500')
S(0x589c20, 'ZFFGameData::GetGameOSD', 'thiscall', ret='eax', gen=_get_osd, note='batch1500')
S(0x589fd0, 'ZFFGameData::GetSquad(int)', 'thiscall', ret='eax', gen=_squad_by_index, note='batch1500')
S(0x589f70, 'ZFFGameData::GetSquad(SSquad*)', 'thiscall', ret='eax', gen=_squad_index, note='batch1500')
S(0x58a360, 'SSquad::RemoveMember', 'thiscall', ret='al', gen=_remove_member, note='batch1500')
S(0x5a2860, 'ZFFActor::RemoveFromSquad', 'thiscall', gen=_actor_remove, note='batch1500')
S(0x59dce0, 'ZFFActor::AddToSquad(SSquad*)', 'thiscall', gen=_actor_add, note='batch1500')
S(0x591d30, 'ZFFHERO::GetFollower', 'thiscall', ret='eax', gen=_get_follower, note='batch1500')
