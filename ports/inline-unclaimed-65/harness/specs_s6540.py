"""specs_s6540.py - unclaimed-65 batch 40 (docs/20-unclaimed-65.md, claim 22): ZWeaponTest::FrameUpdate (thiscall, no arguments). Every
virtual answer is drawn per case: the bools of slots 0xe4, 0xe8 and 0x38 are 0, 1, 0x100 or 0x1234 (so only AL counts, as in the exe), the
slot 0x350 result equals the current item half of the time, the count is 0 to 3 and the index is 0 to 4 (so the wrap and the item compare
both happen). The edge flags 0x6ff994..0x6ff996 start random. The slot 0x184 calls are caller-cleaned; their arguments are logged.
46d5f0 is a logging callee. The cookie is not involved (no /GS frame in this function)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _flush_code(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cstr(c, s):
    a = c.emu.alloc(len(s) + 1, 4)
    c.emu.wbytes(a, s + b'\x00')
    return a


def _pick(seed, *keys):
    """A deterministic answer from the case seed and the call's own arguments (the orig and the port runs must see the same answers)."""
    return (0, 1, 0x100, 0x1234)[hash((seed,) + keys) % 4]


def _setup(c):
    import serial_stubs as ss
    ss.patch(c, 0x46d5f0, c.emu.stub_fn('46d5f0 logger', lambda e, r: (e.calllog.append(('0x46d5f0', e.reg('ecx'), ())),
                                                                       e.ret(eax=0, argbytes=0))))
    _flush_code(c)


def _gen(c):
    seed = c.rng.getrandbits(32)
    # the self object: +0x370 index, +0x1dc count, +0x1e0 the object o, +0x4c the item pointers
    self_ = _rnd(c, 0x400)
    count = c.rng.randint(0, 3)
    c.emu.w32(self_ + 0x1dc, count)
    c.emu.w32(self_ + 0x370, c.rng.randint(0, 4))
    items = []
    for k in range(count + 2):
        it = _rnd(c, 0x20)
        c.emu.w32(it + 4, c.rng.choice([0, _cstr(c, b'Item%d' % k)]))
        items.append(it)
        c.emu.w32(self_ + 0x4c + 4 * k, it)

    # the object o (+0x1e0): slots 0x2d0 (two args, logged), 0x350 (no args: the current item or a fresh value), 0x364 (no args),
    # 0x360 (one arg, logged)
    def s350(e, r):
        e.calllog.append(('0x350', e.reg('ecx'), ()))
        idx = e.r32(self_ + 0x370)
        cur = e.r32((self_ + 0x4c + 4 * idx) & 0xffffffff)     # the index can wrap to 0xffffffff (dec of 0)
        v = cur if _pick(seed, 0x350, idx) & 1 else fresh
        e.ret(eax=v, argbytes=0)

    fresh = c.rng.getrandbits(32)
    o_vt = c.emu.fake_vtable('fu-o', 0x400, {
        0x2d0: lambda e, r: (e.calllog.append(('0x2d0', e.reg('ecx'), (e.arg32(0), e.arg32(1)))), e.ret(eax=0, argbytes=8))[-1],
        0x350: s350,
        0x364: lambda e, r: (e.calllog.append(('0x364', e.reg('ecx'), ())), e.ret(eax=fresh, argbytes=0))[-1],
        0x360: lambda e, r: (e.calllog.append(('0x360', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1],
    })
    o = _rnd(c, 0x40)
    c.emu.w32(o, o_vt)
    c.emu.w32(self_ + 0x1e0, o)

    # the +0x1907 object: slot 0x38 (two args, logged) returns a bool
    o1907_vt = c.emu.fake_vtable('fu-1907', 0x100, {
        0x38: lambda e, r: (e.calllog.append(('0x38_1907', e.reg('ecx'), (e.arg32(0), e.arg32(1)))),
                            e.ret(eax=_pick(seed, 0x38, e.arg32(0), e.arg32(1)), argbytes=8))[-1]})
    o1907 = _rnd(c, 0x40)
    c.emu.w32(o1907, o1907_vt)

    # P objects (slot 0x184: caller-cleaned, the callee's first argument is P; it logs its arguments)
    def s184(e, r):
        # the top call passes four arguments, the loop five; the fifth is only read when the fourth is one of the loop's tags
        # (the stack above a four-argument call is not the callee's to log)
        args = tuple(e.arg32(k) for k in range(4))
        if args[3] in (0x6887bc, 0x6887c0):
            args = args + (e.arg32(4),)
        e.calllog.append(('0x184', args))
        e.ret(eax=0, argbytes=0)

    p_vt = c.emu.fake_vtable('fu-p', 0x300, {0x184: s184})
    p_obj = _rnd(c, 0x40)
    c.emu.w32(p_obj, p_vt)

    # the render object (0x70039c): slot 0x190 returns P, slots 0xe4 and 0xe8 return bools (one argument, logged)
    render_vt = c.emu.fake_vtable('fu-render', 0x300, {
        0x190: lambda e, r: (e.calllog.append(('0x190', e.reg('ecx'), ())), e.ret(eax=p_obj, argbytes=0))[-1],
        0xe8: lambda e, r: (e.calllog.append(('0xe8', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=_pick(seed, 0xe8, e.arg32(0)), argbytes=4))[-1],
        0xe4: lambda e, r: (e.calllog.append(('0xe4', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=_pick(seed, 0xe4, e.arg32(0)), argbytes=4))[-1],
    })
    render = _rnd(c, 0x2000)
    c.emu.w32(render, render_vt)
    c.emu.w32(render + 0x1907, o1907)
    c.emu.w32(0x70039c, render)
    for a in (0x6ff994, 0x6ff995, 0x6ff996):
        c.emu.wbytes(a, bytes([c.rng.choice([0, 1])]))
    return [self_]


S(0x469220, 'ZWeaponTest::FrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-65 batch 40 (claim 22): all branches by per-case answers (bools by AL, counts, index, flags)')
