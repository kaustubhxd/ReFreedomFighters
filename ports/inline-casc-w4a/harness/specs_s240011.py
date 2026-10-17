"""specs_s240011.py - Sonnet-w4a: SEH4 prolog/epilog helpers, __ehvec loops and unwind funclets."""
import pe_emu
from pilot import S
import recruits_util
from recruits_util import rnd, clear_hooks, hook_rec, pystub, seh_chain, STACK_LO, STACK_HI


def _probe(c, on):
    """when on: code hooks on the final `ret` of SEH_prolog4 (exe 0x634b04, port = its copy at +0x44, same layout) log the
    frame it built (ebp-0x1c .. ebp+8), so frame-content mutants become observable"""
    if not on:
        return
    e = c.emu

    def h(em, res):
        ebp = em.reg('ebp')
        ws = [em.r32(ebp + o) for o in range(-0x1c, 0xc, 4)]
        em.calllog.append(('frame',) + tuple(0x57ac0000 if STACK_LO <= w < STACK_HI else w for w in ws))
    for a in (0x634b04, e.decomp[0x634ac0] + 0x44):
        e.hook(a, h)
        recruits_util._HOOKED.add(a)


def _w(c):
    return c.rng.getrandbits(32)


def _seh_side(c):
    """log the head registration record the callee sees: next (stack -> marker), handler, +8 and the try level at +0xc"""
    def side(emu, k):
        a = emu.r32(pe_emu.TEB)
        if a == 0xffffffff:
            emu.calllog.append(('seh', 'end'))
            return
        nxt = emu.r32(a)
        emu.calllog.append(('seh', 0x57ac0000 if STACK_LO <= nxt < STACK_HI else nxt, emu.r32(a + 4), emu.r32(a + 8), emu.r32(a + 0xc)))
    return side


def _vec(c, nargs):
    clear_hooks(c)
    _probe(c, False)
    r = c.rng
    e = c.emu
    e.w32(0x6f5630, _w(c))
    seh_chain(c, r.choice([0, 1, 2]))
    side = _seh_side(c)
    fn = pystub(c, 0, this=True, side=side, ret=lambda em, k: _w(c))
    hook_rec(c, 0x634aae, 0, this=True, pop=0, side=side, ret=lambda em, k: _w(c))
    p = r.choice([0x1000, _w(c) & ~3, rnd(c, 8)])
    size = r.choice([0, 1, 4, 0x1c, 0x40, r.getrandbits(12)])
    count = r.choice([0, 1, 2, 3, 5, r.randrange(7)])
    args = [p, size, count, fn]
    if nargs == 5:
        args.append(_w(c))
    return args


def _g634206(c): return _vec(c, 4)
def _g634123(c): return _vec(c, 5)
def _g63418c(c): return _vec(c, 4)


def _g634ac0(c):
    clear_hooks(c)
    _probe(c, True)
    e = c.emu
    e.w32(0x6f5630, _w(c))
    seh_chain(c, c.rng.choice([0, 1, 2]))
    return [c.rng.choice([0x6dcd48, 0x6dcd88, _w(c)]), c.rng.choice([0, 4, 0x10, 0x18, 0x40])]


def _g634b06(c):
    clear_hooks(c)
    _probe(c, False)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x100)
    ebp = blk + 0x80
    e.w32(ebp - 0x10, r.choice([0xffffffff, _w(c), rnd(c, 12)]))
    return [ebp, _w(c), _w(c), _w(c), _w(c)]


def _funclet(c, a2):
    """parent frame: ebp-relative arguments at fixed offsets; hooked callee 0x634206(p, size, count, fn)"""
    clear_hooks(c)
    _probe(c, False)
    r = c.rng
    e = c.emu
    ebp = pe_emu.STACK_TOP - 0x80
    for off in (8, 0xc, 0x10, 0x14, 0x18):
        e.w32(ebp + off, _w(c))
    hook_rec(c, 0x634206, 4, pop=16, ret=lambda em, k: _w(c))
    flag = r.choice([0, 0, 1, 0x100, _w(c)])
    return [flag, _w(c), _w(c), _w(c)]


def _g634178(c): return _funclet(c, 0)
def _g6341f6(c): return _funclet(c, 1)


S(0x634206, 'GUESS ehvec cleanup loop', 'stdcall', None, ret=None, gen=_g634206, note='batch240011')
S(0x634123, 'GUESS ehvec ctor loop', 'stdcall', None, ret=None, gen=_g634123, note='batch240011')
S(0x63418c, 'GUESS ehvec dtor loop', 'stdcall', None, ret=None, gen=_g63418c, note='batch240011')
S(0x634ac0, 'GUESS SEH_prolog4', 'cdecl', None, ret=None, gen=_g634ac0, note='batch240011')
S(0x634b06, 'GUESS SEH_epilog4', ('regs', ['ebp', 's', 's', 's', 's']), None, ret=None, gen=_g634b06, note='batch240011')
S(0x634178, 'GUESS ehvec ctor unwind funclet', ('regs', ['eax', 'ebx', 'esi', 'edi']), None, ret=None, gen=_g634178, note='batch240011')
S(0x6341f6, 'GUESS ehvec dtor unwind funclet', ('regs', ['eax', 'ebx', 'esi', 'edi']), None, ret=None, gen=_g6341f6, note='batch240011')
