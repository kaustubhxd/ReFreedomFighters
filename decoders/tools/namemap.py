#!/usr/bin/env python3
"""Build the GameCube -> PC function name map (decoders/gc_pc_namemap.tsv).

    python3 -I decoders/tools/namemap.py [--out PATH] [--report PATH] [-v]

Signals, in the order they are applied:
  1. strings   - string literals referenced by exactly one function (<=3 for weak votes) in
                 both builds: assert/error texts, format strings, short extensions ("sgp"),
                 source paths (normalised to the last two path parts).
  2. vtables   - classes present in both builds (PC: MSVC RTTI; GC: _vt.<class> symbols).
                 Slot i of the GC vtable is slot i of the PC vtable; a class is only used
                 when every already-matched slot agrees.
  3. callgraph - for each matched pair, the ordered callee lists are aligned on matched
                 callees; an unmatched 1:1 gap between two anchors votes for a pair.
                 Unmatched sole callers vote the same way. Repeated until nothing changes.
  4. constants - 32-bit immediates and float literals unique to one function in each build
                 (only used for functions nothing else matched, never 'high').
Every accepted pair must pass a size check (GC size / PC size within a band calibrated on
multi-string pairs) and must not contradict string evidence (both sides reference shared
strings but none in common) or callee evidence.

Confidence:
  high   - two independent signals, or >=2 unique strings with high string similarity, or a
           validated vtable slot plus size check, or >=2 callgraph votes from high pairs.
  medium - one clean signal plus size check.
  low    - weak or ambiguous (ICF-folded PC function shared by several GC names, size
           outlier, constants only). Not applied to Ghidra by default.
"""
import sys, os, re, math, argparse, collections, bisect

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ffre  # noqa: E402

# Ground truth from finished format work (formats/oct-format.md, formats/rooms-sgp-format.md, PPO script notes).
# (pc_addr, gc_name_or_addr, source)
GROUND_TRUTH = [
    (0x4edb80, 'InstallCollisionBuffer__14ZCollisionBasePci', 'rooms-sgp-format.md / oct-format.md'),
    (0x4edc50, 'InstallInsideBuffer__14ZCollisionBasePci', 'rooms-sgp-format.md / oct-format.md'),
    (0x53c280, 'Initialize__11ZSoundGraph', 'rooms-sgp-format.md §5'),
    # The docs name the first PC function of each pair the sizer and the second the reader. The
    # code says the reverse: the first ends in 'ret 8' and reads [ebp+8]/[ebp+0xc] (Data(void*,
    # unsigned)), the second is a plain 'ret' (Size()). PC is name-sorted here (Data < Size).
    # Listed corrected; see README "Ground truth".
    (0x490f10, 'GetSoundGraphSize__15ZEngineDataBase', 'oct-format.md SGP (doc swaps sizer/reader)'),
    (0x490e70, 'GetSoundGraphData__15ZEngineDataBasePvUi', 'oct-format.md SGP (doc swaps sizer/reader)'),
    (0x490b30, 'GetRoomColiTreeSize__15ZEngineDataBase', 'oct-format.md (doc swaps sizer/reader)'),
    (0x490a90, 'GetRoomColiTreeData__15ZEngineDataBasePvUi', 'oct-format.md (doc swaps sizer/reader)'),
    (0x490c60, 'GetRoomInsideTreeSize__15ZEngineDataBase', 'oct-format.md (doc swaps sizer/reader)'),
    (0x490bc0, 'GetRoomInsideTreeData__15ZEngineDataBasePvUi', 'oct-format.md (doc swaps sizer/reader)'),
    (0x491340, 'GetTreesSize__15ZEngineDataBase', 'oct-format.md (doc swaps sizer/reader)'),
    (0x4912a0, 'GetTreesData__15ZEngineDataBasePvUi', 'oct-format.md (doc swaps sizer/reader)'),
    (0x48dcb0, 'CreateBoundTrees__15ZEngineDataBase', 'oct-format.md'),
    (0x492170, 'LoadBoundTrees__15ZEngineDataBase', 'oct-format.md'),
    (0x443570, 'LoadBoundTrees__10ZTreeGroupPc', 'oct-format.md'),
    (0x4edcb0, 'LoadInternColiTree__14ZCollisionBasePc', 'oct-format.md'),
    (0x4e3d60, 'Init__15ZOctreeCompiledPv', 'oct-format.md / rooms-sgp-format.md'),
    (0x4e3c20, 0x80275cb0, 'RELATED oct-format.md ConvToOCS: PC 0x4e3c20 is ZOctreeCompiled::CheckPoint with '
                           'ConvToOCS inlined (calls ZNodeCompiled::CheckPoint, ret 8, 32768.0); the map names it CheckPoint'),
    (0x4e3360, 0x80275bec, 'oct-format.md ZOctree::SetOrigin'),
    (0x661bf0, 0x80313418, 'oct-format.md GetColiBits'),
    (0x661bd0, 0x80314e78, 'oct-format.md CreateSubStripId'),
    (0x63ea80, 0x80314e68, 'oct-format.md GetPrimFromStripUniqueId'),
    (0x4ed390, 0x8021802c, 'rooms-sgp-format.md GetRoomsLst'),
    (0x4ed340, 0x8021819c, 'rooms-sgp-format.md GetInsideRoomsLst'),
    (0x4ecb00, 0x802181f0, 'rooms-sgp-format.md GetColiRoomsLst'),
    (0x6616f0, 0x80314e90, 'RELATED task brief: PC strip walker 0x6616f0 decodes the same bits as GC '
                           'GetStripsFromId, but is not its counterpart (it walks triangles; see oct-format.md)'),
]

GC_NOISE = re.compile(r'^(_savegpr|_restgpr|_savefpr|_restfpr|__save_|__restore_|__div2|__mod2|__cvt_|'
                      r'__shr2|__shl2|__ptmf|__va_arg|__pure_virtual|__check_eh_spec|__throw|__rethrow|'
                      r'__eh_|__start_cp_handler|__terminate)')


# PC compiler/CRT helpers without a GameCube counterpart (Ghidra names)
PC_NOISE = re.compile(r'^(__security_check_cookie|@__security_check_cookie@4|guard_check_icall|__std_terminate|'
                      r'__alloca_probe.*|_+report_rangecheckfailure|`eh_vector.*|__SEH_.*|__EH_.*|_CxxThrowException|'
                      r'_+raise_securityfailure|__ArrayUnwind|_+scrt_.*|__RTDynamicCast|ftol|_ftol.*|__alldiv|'
                      r'__allrem|__allmul|__aulldiv|__aullrem|__allshl|__allshr|__aullshr)$')


def log2r(a, b):
    return math.log2(max(a, 1) / max(b, 1))


class Matcher:
    def __init__(self, pc, gc, verbose=False):
        self.pc, self.gc, self.v = pc, gc, verbose
        self.M = {}         # g -> p
        self.Minv = collections.defaultdict(set)   # p -> {g}
        self.info = {}      # g -> (conf, evidence, phase)
        self.proposals = collections.defaultdict(list)  # g -> [(p, signal)] every proposal seen (for agreement stats)
        self._prep()

    # ------------------------------------------------------------------ features
    def _prep(self):
        pc, gc = self.pc, self.gc
        SG, SP = collections.defaultdict(set), collections.defaultdict(set)
        self.gstr, self.pstr = {}, {}
        for g in gc.funcs:
            ss = {ffre.norm_string(s) for _, _, s in gc.strings_of(g)}
            self.gstr[g] = ss
            for s in ss:
                SG[s].add(g)
        for p in pc.funcs:
            ss = {ffre.norm_string(s) for _, _, s in pc.strings_of(p)}
            self.pstr[p] = ss
            for s in ss:
                SP[s].add(p)
        self.vocab = set(SG) & set(SP)
        self.SG, self.SP = SG, SP
        for g in self.gstr:
            self.gstr[g] &= self.vocab
        for p in self.pstr:
            self.pstr[p] &= self.vocab
        self.gnoise = {g for g, f in gc.funcs.items() if GC_NOISE.match(f['name'])}
        # empty / trivial GC functions: MSVC inlines or folds them, so they only disturb call lists
        self.gtiny = {g for g, f in gc.funcs.items() if f['size'] <= 8}
        self.pnoise = {p for p, f in pc.funcs.items() if PC_NOISE.match(f['name'])}
        # resolve PC thunks (single jmp) to their target
        thunk = {}
        for p, f in pc.funcs.items():
            if f.get('thunk') or f['name'].startswith('thunk_'):
                cl = pc.an['calls'].get(p, [])
                if len(cl) == 1 and cl[0][2]:
                    thunk[p] = cl[0][1]
        self.pthunk = thunk
        def pcl(p):
            out = []
            for c in pc.callees(p):
                c = thunk.get(c, c)
                if c != p and c in pc.funcs and c not in self.pnoise and c not in out:
                    out.append(c)
            return out
        self.gcallees = {g: [c for c in gc.callees(g) if c != g and c not in self.gnoise and c not in self.gtiny
                             and c in gc.funcs] for g in gc.funcs}
        self.pcallees = {p: pcl(p) for p in pc.funcs}
        self.gcallers = collections.defaultdict(list)
        for g, cl in self.gcallees.items():
            for c in cl:
                self.gcallers[c].append(g)
        self.pcallers = collections.defaultdict(list)
        for p, cl in self.pcallees.items():
            for c in cl:
                self.pcallers[c].append(p)
        self.gfl = {g: set(gc.floats_of(g)) for g in gc.funcs}
        self.pfl = {p: set(pc.floats_of(p)) for p in pc.funcs}
        self.gconst = {g: set(gc.an['consts'].get(g, [])) for g in gc.funcs}
        self.pconst = {p: set(pc.an['consts'].get(p, [])) for p in pc.funcs}

    def size_lr(self, g, p):
        return log2r(self.gc.funcs[g]['size'], self.pc.funcs[p]['size'])

    def size_ok(self, g, p, loose=False):
        lr = self.size_lr(g, p)
        lo, hi = (self.band_loose if loose else self.band)
        # tiny functions: absolute sizes are dominated by prologue differences
        if self.gc.funcs[g]['size'] <= 32 and self.pc.funcs[p]['size'] <= 24:
            return True
        return lo <= lr <= hi

    def str_sim(self, g, p):
        a, b = self.gstr.get(g, set()), self.pstr.get(p, set())
        if not a and not b:
            return None
        return len(a & b) / len(a | b)

    def str_conflict(self, g, p):
        """Both reference shared-vocabulary strings, none in common (ignoring source paths)."""
        a = {s for s in self.gstr.get(g, ()) if not s.startswith('FILE:')}
        b = {s for s in self.pstr.get(p, ()) if not s.startswith('FILE:')}
        fa = {s for s in self.gstr.get(g, ()) if s.startswith('FILE:')}
        fb = {s for s in self.pstr.get(p, ()) if s.startswith('FILE:')}
        if fa and fb and not (fa & fb):
            return True
        return bool(a) and bool(b) and not (a & b)

    def callee_consistency(self, g, p):
        """(agree, total) over matched callees of g."""
        cp = set(self.pcallees.get(p, ()))
        agree = total = 0
        for c in self.gcallees.get(g, ()):
            if c in self.M:
                total += 1
                if self.M[c] in cp:
                    agree += 1
        return agree, total

    def caller_consistency(self, g, p):
        cp = set(self.pcallers.get(p, ()))
        agree = total = 0
        for c in self.gcallers.get(g, ()):
            if c in self.M:
                total += 1
                if self.M[c] in cp:
                    agree += 1
        return agree, total

    def float_conflict(self, g, p):
        a, b = self.gfl.get(g, set()) - {0.0, 1.0}, self.pfl.get(p, set()) - {0.0, 1.0}
        return len(a) >= 2 and len(b) >= 2 and not (a & b)

    def contradicts(self, g, p):
        if self.str_conflict(g, p):
            return 'strings'
        a, t = self.callee_consistency(g, p)
        if t >= 3 and a * 3 < t:
            return 'callees %d/%d' % (a, t)
        a, t = self.caller_consistency(g, p)
        if t >= 3 and a * 3 < t:
            return 'callers %d/%d' % (a, t)
        if self.float_conflict(g, p):
            return 'floats'
        return None

    def settled(self, g):
        """Matched with medium/high confidence, or low because the PC function is shared (ICF)."""
        if g not in self.M:
            return False
        c, ev, ph = self.info[g]
        return c != 'low' or 'icf' in ev

    def pfree(self, p, but=None):
        return not any(self.settled(x) for x in self.Minv.get(p, ()) if x != but)

    def accept(self, g, p, conf, ev, phase):
        if g in self.M:
            self.Minv[self.M[g]].discard(g)
        self.M[g] = p
        self.Minv[p].add(g)
        self.info[g] = [conf, ev, phase]

    # ------------------------------------------------------------------ phase 1: strings
    def phase_strings(self):
        gc, pc = self.gc, self.pc
        hold = getattr(self, 'holdout', set())
        score = collections.defaultdict(float)
        nuniq = collections.Counter()
        best_s = {}
        for s in self.vocab:
            G, P = self.SG[s], self.SP[s]
            if s.startswith('FILE:'):
                continue
            if len(G) > 3 or len(P) > 3:
                continue
            w = 1.0 / max(len(G), len(P))
            if len(s) < 6:
                w *= 0.5
            for g in G:
                for p in P:
                    score[(g, p)] += w
                    if len(G) == 1 and len(P) == 1:
                        nuniq[(g, p)] += 1
                        if len(s) > len(best_s.get((g, p), '')):
                            best_s[(g, p)] = s
        # calibrate the size band on pairs with >=2 unique strings
        rs = sorted(self.size_lr(g, p) for (g, p), n in nuniq.items() if n >= 2)
        med = rs[len(rs) // 2]
        q = lambda f: rs[int(len(rs) * f)]
        self.band = (min(q(0.03), med - 1.0), max(q(0.97), med + 1.0))
        self.band_loose = (self.band[0] - 0.8, self.band[1] + 0.8)
        self.size_stats = (len(rs), med, q(0.1), q(0.9))
        cands = sorted(score.items(), key=lambda kv: (-kv[1], -nuniq[kv[0]], -(self.str_sim(*kv[0]) or 0)))
        usedp = set()
        for (g, p), sc in cands:
            self.proposals[g].append((p, 'str'))
            if g in self.M or p in usedp or g in hold:
                continue
            nu = nuniq[(g, p)]
            sim = self.str_sim(g, p) or 0
            ok = self.size_ok(g, p)
            okl = self.size_ok(g, p, loose=True)
            if sc < 0.5 or not okl:
                continue
            if nu >= 2 and sim >= 0.5 and ok:
                conf = 'high'
            elif nu >= 3 and sim >= 0.6:
                conf = 'high'      # many shared unique strings: size may differ (inlining, big switch)
            elif nu >= 1 and sim >= 0.8 and ok and len(best_s.get((g, p), '')) >= 10:
                conf = 'high'
            elif nu >= 1 and sim >= 0.34 and ok:
                conf = 'medium'
            elif sc >= 1 and sim >= 0.5 and okl:
                conf = 'medium' if ok else 'low'
            else:
                conf = 'low'
            ev = 'str:%du/%.1f sim=%.2f size=%.2f' % (nu, sc, sim, self.size_lr(g, p))
            if (g, p) in best_s:
                ev += ' "%s"' % best_s[(g, p)][:40].replace('\t', ' ').replace('\n', ' ')
            self.accept(g, p, conf, ev, 'strings')
            usedp.add(p)


    # ------------------------------------------------------------------ phase 2: vtables
    def _vt_perm(self, gs):
        """GC slot -> PC slot. MSVC groups overloads of one name and emits them in reverse
        declaration order; GCC keeps declaration order. Reverse runs of adjacent overloads."""
        names = []
        for g in gs:
            nm = self.gc.funcs[g]['name'] if g in self.gc.funcs else ''
            names.append(ffre.short_demangled(ffre.demangle(nm)).split('::')[-1] if nm else '')
        perm = list(range(len(gs)))
        i = 0
        while i < len(gs):
            j = i
            while j + 1 < len(gs) and names[j + 1] and names[j + 1] == names[i] and gs[j + 1] != gs[i]:
                j += 1
            if j > i and names[i] not in ('__pure_virtual',):
                for k in range(i, j + 1):
                    perm[k] = j - (k - i)
            i = j + 1
        return perm

    def _vt_align(self, gs, ps):
        """Needleman-Wunsch alignment of GC slots (already in MSVC overload order) to PC slots.
        Returns [(i, j, clean)] for aligned slot pairs; clean = no gap right next to it."""
        n, m = len(gs), len(ps)
        GAP = -2.5
        def sc(i, j):
            g, p = gs[i], ps[j]
            if g in self.M and self.info[g][0] != 'low':
                if self.M[g] == p:
                    return 8.0
                return -1.0 if p in self.pc_stub else -8.0
            if g not in self.gc.funcs or p not in self.pc.funcs:
                return -1.0
            if p in self.pc_stub:
                return 0.5 if self.gc.funcs[g]['size'] <= 24 else -1.0
            return 1.0 if self.size_ok(g, p) else -2.0
        NEG = -1e9
        D = [[0.0] * (m + 1) for _ in range(n + 1)]
        B = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            D[i][0] = GAP * i; B[i][0] = 1
        for j in range(1, m + 1):
            D[0][j] = GAP * j; B[0][j] = 2
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                d = D[i - 1][j - 1] + sc(i - 1, j - 1)
                u = D[i - 1][j] + GAP
                l = D[i][j - 1] + GAP
                if d >= u and d >= l:
                    D[i][j] = d; B[i][j] = 0
                elif u >= l:
                    D[i][j] = u; B[i][j] = 1
                else:
                    D[i][j] = l; B[i][j] = 2
        i, j = n, m
        moves = []
        while i > 0 or j > 0:
            b = B[i][j]
            moves.append((b, i - 1, j - 1))
            if b == 0:
                i -= 1; j -= 1
            elif b == 1:
                i -= 1
            else:
                j -= 1
        moves.reverse()
        out = []
        for k, (b, i, j) in enumerate(moves):
            if b != 0:
                continue
            clean = (k == 0 or moves[k - 1][0] == 0) and (k + 1 == len(moves) or moves[k + 1][0] == 0)
            out.append((i, j, clean))
        return out

    def phase_vtables(self):
        gc, pc = self.gc, self.pc
        vg, vp = gc.vtables(), pc.vtables()
        self._vt_both = sorted(set(vg) & set(vp))
        # platform classes: ZCollisionGC ~ ZCollisionWintel, ZDrawArray<ZGeomDrawEntryGC,...> ~ <...D3D,...>
        stem = lambda c: re.sub(r'(GC|Wintel|D3D|X86|PC)(?=$|,|>)', '', c)
        sp = collections.defaultdict(list)
        for c in set(vp) - set(vg):
            sp[stem(c)].append(c)
        xplat = {}
        for c in sorted(set(vg) - set(vp)):
            if stem(c) != c and sp.get(stem(c)):
                lg = len([x for x in vg[c][1] if x])
                cands = sorted(sp[stem(c)], key=lambda pcn: (abs(len(vp[pcn][1]) - lg), pcn))
                if len(cands) > 1 and abs(len(vp[cands[0]][1]) - lg) == abs(len(vp[cands[1]][1]) - lg):
                    continue
                xplat[c] = cands[0]
        self.vt_xplat = xplat
        pairs = [(c, c) for c in self._vt_both] + sorted(xplat.items())
        votes = collections.defaultdict(lambda: collections.defaultdict(list))   # g -> p -> [(class, slot, anchored, clean)]
        self.vt_classes_used = 0
        self.vt_classes_gapped = 0
        self.vt_classes_rejected = []
        # PC slot targets shared by several different GC functions = stubs / identical-code folding
        slot_g = collections.defaultdict(set)
        tables = {}
        for cls, pcls in pairs:
            gs = list(vg[cls][1])
            while gs and gs[-1] == 0:
                gs.pop()
            perm = self._vt_perm(gs)
            gsp = [0] * len(gs)
            for i, k in enumerate(perm):
                gsp[k] = gs[i]
            ps = vp[pcls][1]
            tables[cls] = (gsp, ps)
            if len(gsp) == len(ps) and cls == pcls:
                for i in range(len(ps)):
                    if gsp[i]:
                        slot_g[ps[i]].add(gsp[i])
        self.pc_stub = {p for p, gsets in slot_g.items() if len(gsets) > 1} | \
                       {p for p, f in pc.funcs.items() if f['size'] <= 6}
        for cls, pcls in pairs:
            gs, ps = tables[cls]
            al = self._vt_align(gs, ps)
            gapped = len(al) != len(gs) or len(al) != len(ps)
            agree = disagree = 0
            bad = []
            for i, j, clean in al:
                g, p = gs[i], ps[j]
                if p in self.pc_stub:
                    continue
                if g in self.M and self.info[g][0] != 'low':
                    if self.M[g] == p:
                        agree += 1
                    else:
                        disagree += 1
                        bad.append(i)
            if disagree:
                self.vt_classes_rejected.append((cls, 'slots %s disagree with anchors (%d agree)' % (bad[:4], agree)))
                continue
            if gapped:
                self.vt_classes_gapped += 1
            else:
                self.vt_classes_used += 1
            for i, j, clean in al:
                g, p = gs[i], ps[j]
                if not g or g not in gc.funcs or p not in pc.funcs:
                    continue
                if p not in self.pc_stub:
                    slot_g[p].add(g)
                votes[g][p].append((cls if cls == pcls else '%s~%s' % (cls, pcls), i, agree,
                                    clean and not (gapped and agree < 2) and cls == pcls))
        self.pc_stub |= {p for p, gsets in slot_g.items() if len(gsets) > 1}
        for g, d in votes.items():
            for p in d:
                self.proposals[g].append((p, 'vt'))
            if g in self.M:
                continue
            if self.gc.funcs[g]['name'] == '__pure_virtual':
                continue
            if len(d) != 1:
                continue   # same GC function in slots that point to different PC functions
            (p, vl), = d.items()
            classes = sorted({c for c, i, a, cl in vl})
            anchored = any(a > 0 for c, i, a, cl in vl)
            same = [(c, i, a, cl) for c, i, a, cl in vl if '~' not in c]
            clean = bool(same) and all(cl for c, i, a, cl in same)   # xplat-only slots are never clean
            anchored = any(a > 0 for c, i, a, cl in (same or vl))
            ev = 'vt:%s[%d]' % (classes[0], vl[0][1]) + ('+%d' % (len(classes) - 1) if len(classes) > 1 else '')
            ev += ' size=%.2f' % self.size_lr(g, p)
            if self.gc.funcs[g]['name'].startswith(('_._', '_$_')):
                ev += ' dtor-slot(PC: scalar deleting dtor)'
            if p in self.pc_stub or self.Minv.get(p):
                others = (slot_g[p] | self.Minv.get(p, set())) - {g}
                conf = 'low'
                ev += ' icf/stub(PC fn shared by %d GC fns)' % (len(others) + 1)
            else:
                c = self.contradicts(g, p)
                if c:
                    continue
                ok = self.size_ok(g, p)
                if not clean:
                    ev += ' near-gap'
                if ok and clean and (anchored or len({c for c, _, _, _ in same}) >= 2):
                    conf = 'high'
                elif ok or self.size_ok(g, p, loose=True):
                    conf = 'medium'
                else:
                    conf = 'low'
            self.accept(g, p, conf, ev, 'vtables')

    # ------------------------------------------------------------------ phase 3: callgraph
    def _align_votes(self, g, p, votes):
        gl, pl = self.gcallees.get(g, []), self.pcallees.get(p, [])
        if not gl or not pl:
            return
        pidx = {}
        for j, c in enumerate(pl):
            pidx.setdefault(c, j)
        # anchors: matched callees in increasing order on both sides
        anchors = [(-1, -1)]
        lastj = -1
        for i, c in enumerate(gl):
            if c in self.M and self.M[c] in pidx and pidx[self.M[c]] > lastj:
                lastj = pidx[self.M[c]]
                anchors.append((i, lastj))
        anchors.append((len(gl), len(pl)))
        src_conf = self.info[g][0]
        for (i0, j0), (i1, j1) in zip(anchors, anchors[1:]):
            gg = [c for c in gl[i0 + 1:i1] if not self.settled(c)]
            pp = [c for c in pl[j0 + 1:j1] if self.pfree(c)]
            if len(gg) == 1 and len(pp) == 1:
                votes[(gg[0], pp[0])].append((g, 'callee', src_conf, 1.0))
            elif 1 < len(gg) == len(pp) <= 4:
                for a, b in zip(gg, pp):
                    votes[(a, b)].append((g, 'callee-seq', src_conf, 0.5))
        # sole unmatched caller
        gcl = [c for c in self.gcallers.get(g, []) if not self.settled(c)]
        pcl = [c for c in self.pcallers.get(p, []) if self.pfree(c)]
        if len(gcl) == 1 and len(pcl) == 1:
            votes[(gcl[0], pcl[0])].append((g, 'caller', src_conf, 1.0))

    def _signature_votes(self, votes):
        """An unmatched GC function whose matched callers (or callees) map onto the callers
        (callees) of exactly one unmatched PC function votes for that function, once per
        agreeing neighbour."""
        good = lambda x: x in self.M and self.info[x][0] != 'low'
        pfree = self.pfree
        for g in self.gc.funcs:
            if self.settled(g) or g in self.gnoise:
                continue
            for kind, gn, pn, rev in (('callers-set', self.gcallers, self.pcallees, self.pcallers),
                                      ('callees-set', self.gcallees, self.pcallers, self.pcallees)):
                nb = [c for c in set(gn.get(g, ())) if good(c)]
                if len(nb) < 2:
                    continue
                cnt = collections.Counter()
                for c in nb:
                    for p in set(pn.get(self.M[c], ())):
                        if pfree(p):
                            cnt[p] += 1
                if not cnt:
                    continue
                top = cnt.most_common(2)
                p, k = top[0]
                if k < 2 or k < 0.6 * len(nb) or (len(top) > 1 and top[1][1] == k):
                    continue
                pnb = [x for x in set(rev.get(p, ())) if not pfree(x)]
                jac = k / float(len(nb) + len(pnb) - k) if (len(nb) + len(pnb) - k) else 0
                if jac < 0.5:
                    continue
                w = 1.0 if jac >= 0.75 else 0.5
                for c in nb:
                    if self.M[c] in set(rev.get(p, ())):
                        votes[(g, p)].append((c, kind, self.info[c][0], w))

    def phase_callgraph(self, rounds=30):
        for rnd in range(rounds):
            votes = collections.defaultdict(list)
            for g, p in list(self.M.items()):
                if self.info[g][0] == 'low':
                    continue
                self._align_votes(g, p, votes)
            self._signature_votes(votes)
            byg = collections.defaultdict(dict)
            for (g, p), vl in votes.items():
                byg[g][p] = vl
                self.proposals[g].append((p, 'cg'))
            byp = collections.defaultdict(set)
            for (g, p) in votes:
                byp[p].add(g)
            added = 0
            for g, d in byg.items():
                if self.settled(g):
                    continue
                ranked = sorted(d.items(), key=lambda kv: -sum(w for _, _, _, w in kv[1]))
                p, vl = ranked[0]
                s1 = sum(w for _, _, _, w in vl)
                s2 = sum(w for _, _, _, w in ranked[1][1]) if len(ranked) > 1 else 0
                if s2 and s1 < 2 * s2:
                    continue
                if not self.pfree(p, but=g):
                    continue
                # the PC side must not be claimed more strongly by another GC function
                rival = max((sum(w for _, _, _, w in votes[(g2, p)]) for g2 in byp[p] if g2 != g), default=0)
                if rival and s1 < 2 * rival:
                    continue
                if self.contradicts(g, p):
                    continue
                srcs = {s for s, _, _, _ in vl}
                strong_hi = {s for s, k, c, w in vl if w >= 1 and c == 'high'}
                strong = {s for s, k, c, w in vl if w >= 1}
                ok = self.size_ok(g, p)
                okl = self.size_ok(g, p, loose=True)
                sim = self.str_sim(g, p)
                ca, ct = self.callee_consistency(g, p)
                extra = (sim is not None and sim > 0) or (ct >= 2 and ca == ct)
                if not okl:
                    continue
                if ok and (len(strong_hi) >= 2 or (len(strong_hi) >= 1 and extra)):
                    conf = 'high'
                elif ok and (len(strong) >= 1 or len(srcs) >= 2):
                    conf = 'medium'
                else:
                    conf = 'low'
                kinds = collections.Counter(k for _, k, _, _ in vl)
                srcname = ffre.short_demangled(ffre.demangle(self.gc.funcs[vl[0][0]]['name']))
                ev = 'cg:%s via %s%s size=%.2f' % ('+'.join('%s%s' % (k, 'x%d' % n if n > 1 else '') for k, n in kinds.items()),
                                                   srcname[:40], ' +%d' % (len(srcs) - 1) if len(srcs) > 1 else '',
                                                   self.size_lr(g, p))
                if ct:
                    ev += ' callees=%d/%d' % (ca, ct)
                if g in self.M and conf == 'low':
                    continue      # already low; nothing new
                self.accept(g, p, conf, ev, 'callgraph')
                added += 1
            if self.v:
                print('  callgraph round %d: +%d' % (rnd, added), file=sys.stderr)
            if not added:
                break

    # ------------------------------------------------------------------ phase 3c: ambiguous string groups
    def phase_string_groups(self):
        """2-3 GC functions and the same number of PC functions share a string nothing else uses
        (e.g. GetTreesSize/GetTreesData both use "oct"). Pair them by source order (GC address
        order = PC address order in source-ordered units) or by MSVC name order (name-sorted
        units). When both orders give the same pairing -> medium; otherwise the order of
        already-matched neighbours in the same unit decides (medium if >=2 agree, low if 1)."""
        hold = getattr(self, 'holdout', set())
        free_g = lambda g: (g not in self.M or self.info[g][0] == 'low') and g not in hold
        free_p = lambda p: not any(self.info[x][0] != 'low' for x in self.Minv.get(p, ()))
        good = [(g, p) for g, p in self.M.items() if self.info[g][0] != 'low']
        added = 0
        for st in sorted(self.vocab):
            G, P = self.SG[st], self.SP[st]
            if st.startswith('FILE:') or not (2 <= len(G) == len(P) <= 3):
                continue
            if not all(free_g(g) for g in G) or not all(free_p(p) for p in P):
                continue
            if len({self.gc.cu_of(g) for g in G}) != 1 or max(P) - min(P) > 0x4000:
                continue
            cu = self.gc.cu_of(min(G))
            pa = sorted(P)
            by_src = tuple(zip(sorted(G), pa))
            keys = sorted(G, key=lambda g: msvc_key(self.gc.funcs[g]['name']))
            if len({msvc_key(self.gc.funcs[g]['name']) for g in G}) != len(G):
                by_name = None
            else:
                by_name = tuple(zip(keys, pa))
            if by_src == by_name:
                pairs, conf, why = by_src, 'medium', 'src=name order'
            else:
                g0, p0 = min(G), min(P)
                k0 = msvc_key(self.gc.funcs[g0]['name'])
                vs = vn = 0
                for g, p in good:
                    if abs(p - p0) > 0x1000 or self.gc.cu_of(g) != cu or p in P:
                        continue
                    sp = p > p0
                    vs += ((g > g0) == sp)
                    vn += ((msvc_key(self.gc.funcs[g]['name']) > k0) == sp)
                if vs > vn:
                    pairs, n = by_src, vs - vn
                    why = 'src order (neighbours %d:%d)' % (vs, vn)
                elif vn > vs and by_name:
                    pairs, n = by_name, vn - vs
                    why = 'name order (neighbours %d:%d)' % (vn, vs)
                else:
                    continue
                conf = 'medium' if n >= 2 else 'low'
            if any(not self.size_ok(g, p, loose=True) for g, p in pairs):
                continue
            for g, p in pairs:
                self.proposals[g].append((p, 'strgrp'))
                if g in self.M:
                    if self.M[g] == p:
                        continue
                    self.Minv[self.M[g]].discard(g)
                self.accept(g, p, conf, 'str-group:%d-way "%s" by %s size=%.2f' % (len(G), st[:30], why, self.size_lr(g, p)),
                            'strings')
                added += 1
        return added

    # ------------------------------------------------------------------ phase 3b: link order
    def phase_order(self):
        """Inside one compilation unit the PC linker emitted functions sorted by MSVC decorated
        name (about 80% of units; a few keep source order). GC keeps source order and marks each
        unit with a 'gcc2_compiled.' label. Two matched functions of one unit that are adjacent in
        the PC address space bracket the unmatched functions between them; if the GC unit has the
        same number of unmatched functions whose sort key falls in the bracket, pair them in order."""
        gc, pc = self.gc, self.pc
        good = {g: p for g, p in self.M.items() if self.info[g][0] != 'low'}
        goodp = sorted(set(good.values()))
        nextp = {a: b for a, b in zip(goodp, goodp[1:])}
        def gkey(g):
            k = msvc_key(gc.funcs[g]['name'])
            if self.info.get(g, [''] * 3)[1].find('dtor-slot') >= 0:
                k = k.replace('??1', '??_G', 1)
            return k
        bycu = collections.defaultdict(list)
        for g, p in good.items():
            bycu[gc.cu_of(g)].append((p, g))
        unm_by_cu = collections.defaultdict(list)
        for g in gc.funcs:
            if g not in self.M or self.info[g][0] == 'low':
                if g not in self.gnoise:
                    unm_by_cu[gc.cu_of(g)].append(g)
        pcs = sorted(pc.funcs)
        added = 0
        props = []
        self.order_modes = collections.Counter()
        keyf = {'name': gkey, 'src': (lambda g: g)}
        for cu, L in bycu.items():
            L.sort()
            for idx in range(len(L) - 1):
                (p1, g1), (p2, g2) = L[idx], L[idx + 1]
                if nextp.get(p1) != p2 or p2 - p1 > 0x10000:
                    continue
                win = L[max(0, idx - 3):idx + 5]
                steps = [(a, b) for a, b in zip(win, win[1:]) if b[0] - a[0] <= 0x20000]
                if len(steps) < 2:
                    continue
                results = {}
                for mode, key in keyf.items():
                    if not all(key(a[1]) < key(b[1]) for a, b in steps):
                        continue
                    k1, k2 = key(g1), key(g2)
                    i1 = bisect.bisect_right(pcs, p1)
                    i2 = bisect.bisect_left(pcs, p2)
                    upc = [p for p in pcs[i1:i2] if not any(self.info[x][0] != 'low' for x in self.Minv.get(p, ()))]
                    ugc = [g for g in unm_by_cu[cu] if k1 < key(g) < k2]
                    if not upc or len(upc) != len(ugc) or len(upc) > 8:
                        results[mode] = None
                        continue
                    ugc.sort(key=key)
                    if len({key(g) for g in ugc}) != len(ugc):
                        results[mode] = None
                        continue
                    results[mode] = tuple(zip(ugc, upc))
                got = {v for v in results.values() if v}
                if len(got) != 1:
                    continue
                pairs = list(got.pop())
                mode = '+'.join(sorted(m for m, v in results.items() if v))
                self.order_modes[mode] += 1
                if any(not self.size_ok(g, p, loose=True) or self.contradicts(g, p) for g, p in pairs):
                    continue
                if sum(1 for g, p in pairs if not self.size_ok(g, p)) > len(pairs) // 3:
                    continue
                for g, p in pairs:
                    props.append((g, p, mode, len(pairs), g1, g2))
        for g, p, mode, n, g1, g2 in props:
            self.proposals[g].append((p, 'order'))
            if g in self.M and (self.info[g][0] != 'low' or self.info[g][2] == 'order' or self.M[g] == p):
                continue
            if any(self.info[x][0] != 'low' for x in self.Minv.get(p, ())):
                continue
            ok = self.size_ok(g, p)
            sim = self.str_sim(g, p)
            ca, ct = self.callee_consistency(g, p)
            ra, rt = self.caller_consistency(g, p)
            corrob = (sim is not None and sim > 0) or (ct + rt >= 1 and ca + ra == ct + rt)
            if n == 1 and ok and corrob:
                conf = 'high'
            elif ok and (n <= 2 or corrob):
                conf = 'medium'
            else:
                conf = 'low'
            if g in self.M:   # replace a low match
                self.Minv[self.M[g]].discard(g)
            ev = 'order:%s 1-of-%d between %s..%s size=%.2f' % (
                mode, n, ffre.short_demangled(ffre.demangle(gc.funcs[g1]['name'])).split('::')[-1][:24],
                ffre.short_demangled(ffre.demangle(gc.funcs[g2]['name'])).split('::')[-1][:24], self.size_lr(g, p))
            if ct + rt:
                ev += ' graph=%d/%d' % (ca + ra, ct + rt)
            self.accept(g, p, conf, ev, 'order')
            added += 1
        return added

    # ------------------------------------------------------------------ phase 4: constants
    def phase_constants(self):
        def index(feat):
            idx = collections.defaultdict(set)
            for f, vals in feat.items():
                for v in vals:
                    idx[v].add(f)
            return idx
        gfeat = {g: {('c', v) for v in self.gconst[g] if v >= 0x10000 and v & 0xffff and v not in (0xffffffff,)} |
                 {('f', v) for v in self.gfl[g] if v not in (0.0, 1.0, -1.0, 0.5, 2.0)} for g in self.gc.funcs}
        pfeat = {p: {('c', v) for v in self.pconst[p] if v >= 0x10000 and v & 0xffff and v not in (0xffffffff,)} |
                 {('f', v) for v in self.pfl[p] if v not in (0.0, 1.0, -1.0, 0.5, 2.0)} for p in self.pc.funcs}
        gi, pi = index(gfeat), index(pfeat)
        score = collections.Counter()
        for v in set(gi) & set(pi):
            if len(gi[v]) == 1 and len(pi[v]) == 1:
                score[(next(iter(gi[v])), next(iter(pi[v])))] += 1
        for (g, p), n in score.most_common():
            self.proposals[g].append((p, 'const'))
            if g in self.M or self.Minv.get(p) or n < 2:
                continue
            if not self.size_ok(g, p) or self.contradicts(g, p):
                continue
            ca, ct = self.callee_consistency(g, p)
            conf = 'medium' if (n >= 3 or (ct >= 1 and ca == ct)) else 'low'
            self.accept(g, p, conf, 'const:%d unique size=%.2f' % (n, self.size_lr(g, p)) +
                        (' callees=%d/%d' % (ca, ct) if ct else ''), 'constants')

    # ------------------------------------------------------------------ post: re-check everything
    def recheck(self):
        """Demote pairs whose callees/callers now contradict the final map."""
        dem = 0
        for g, p in list(self.M.items()):
            conf, ev, ph = self.info[g]
            c = self.contradicts(g, p)
            if c and conf != 'low':
                self.info[g][0] = 'low' if conf == 'medium' else 'medium'
                self.info[g][1] += ' DEMOTED(%s)' % c
                dem += 1
            elif conf == 'medium':
                ca, ct = self.callee_consistency(g, p)
                ra, rt = self.caller_consistency(g, p)
                if ct + rt >= 3 and ca + ra == ct + rt and self.size_ok(g, p):
                    self.info[g][0] = 'high'
                    self.info[g][1] += ' +graph(%d/%d)' % (ca + ra, ct + rt)
            elif conf == 'low' and 'icf' not in ev and len(self.Minv[p]) == 1:
                ca, ct = self.callee_consistency(g, p)
                ra, rt = self.caller_consistency(g, p)
                if ct + rt and ca + ra == ct + rt and self.size_ok(g, p, loose=True) and \
                        (ct + rt >= 2 or ev.startswith('str:')):
                    self.info[g][0] = 'medium'
                    self.info[g][1] += ' +graph(%d/%d)' % (ca + ra, ct + rt)
        return dem

    def run(self):
        self.phase_strings()
        n1 = len(self.M)
        self.phase_vtables()
        n2 = len(self.M)
        for it in range(10):
            a = len(self.M)
            self.phase_callgraph()
            o = self.phase_order()
            o += self.phase_string_groups()
            if self.v:
                print('iteration %d: callgraph+order now %d matched (order +%d)' % (it, len(self.M), o), file=sys.stderr)
            if len(self.M) == a and not o:
                break
        n3 = len(self.M)
        self.phase_constants()
        self.phase_callgraph()
        n4 = len(self.M)
        dem = self.recheck()
        self.phase_counts = {'strings': n1, 'vtables': n2 - n1, 'callgraph+order': n3 - n2, 'constants+cg2': n4 - n3,
                             'demoted': dem}


_MSVC_OPS = {'nw': '2', 'dl': '3', 'as': '4', 'eq': '8', 'ne': '9', 'vc': 'A', 'rf': 'C', 'ml': 'D', 'pp': 'E',
             'mm': 'F', 'mi': 'G', 'pl': 'H', 'ad': 'I', 'lt': 'M', 'le': 'N', 'gt': 'O', 'ge': 'P', 'cl': 'R',
             'co': 'S', 'er': 'T', 'or': 'U', 'aa': 'V', 'oo': 'W', 'aml': 'X', 'apl': 'Y', 'ami': 'Z',
             'vn': '_U', 'vd': '_V', 'adv': '_0', 'amd': '_1', 'als': '_3', 'ars': '_2', 'aad': '_4',
             'aor': '_5', 'aer': '_6', 'nt': '7', 'ls': '6', 'rs': '5', 'dv': 'K', 'md': 'L'}


def msvc_key(name):
    """Approximate prefix of the MSVC decorated name of a GCC2-mangled function (sort key)."""
    dm = ffre.demangle(name)
    if dm == name:
        return '_' + name          # extern "C"
    base = re.sub(r'<.*?>', '', ffre.short_demangled(dm))
    parts = base.split('::')
    meth, cls = parts[-1], parts[:-1]
    clss = '@'.join(reversed(cls))
    if name.startswith(('_._', '_$_')):
        return '??1' + clss + '@@'
    if cls and meth == cls[-1]:
        return '??0' + clss + '@@'
    m = re.match(r'^__([a-z]+)__', name)
    if m and m.group(1) in _MSVC_OPS:
        return '??' + _MSVC_OPS[m.group(1)] + clss + '@@'
    if meth.startswith('operator '):
        return '??B' + clss + '@@'
    return '?' + meth + '@' + (clss + '@@' if clss else '@')


def gc_lookup(gc, x):
    if isinstance(x, int):
        return x
    v = gc.byname.get(x)
    return [a for a in v if a in gc.funcs][0] if v else None


def holdout_run(pc, gc, a):
    import random
    ref = Matcher(pc, gc)
    ref.phase_strings()
    truth = {g: p for g, p in ref.M.items() if ref.info[g][0] == 'high' and ref.info[g][1].startswith('str:')}
    rnd = random.Random(a.seed)
    hold = set(rnd.sample(sorted(truth), int(len(truth) * a.holdout)))
    m = Matcher(pc, gc, a.v)
    m.holdout = hold
    m.run()
    res = collections.Counter()
    for g in hold:
        if g not in m.M:
            res[('missing', '-')] += 1
            continue
        conf, ev, ph = m.info[g]
        res[(ph, conf, m.M[g] == truth[g])] += 1
    print('Hold-out validation: %d of %d high-confidence string pairs hidden from the string phase (seed %d)'
          % (len(hold), len(truth), a.seed))
    print('  not re-matched: %d' % res[('missing', '-')])
    for ph in ('vtables', 'callgraph', 'order', 'constants', 'strings'):
        for conf in ('high', 'medium', 'low'):
            ok, bad = res[(ph, conf, True)], res[(ph, conf, False)]
            if ok + bad:
                print('  %-10s %-6s correct %4d  wrong %3d  precision %.1f%%' % (ph, conf, ok, bad, 100.0 * ok / (ok + bad)))
    for conf in ('high', 'medium', 'low'):
        ok = sum(v for k, v in res.items() if len(k) == 3 and k[1] == conf and k[2])
        bad = sum(v for k, v in res.items() if len(k) == 3 and k[1] == conf and not k[2])
        if ok + bad:
            print('  ALL        %-6s correct %4d  wrong %3d  precision %.1f%%' % (conf, ok, bad, 100.0 * ok / (ok + bad)))
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--out', default=ffre.NAMEMAP)
    ap.add_argument('--report', default=None, help='also write the report to this file')
    ap.add_argument('-v', action='store_true')
    ap.add_argument('--holdout', type=float, default=0,
                    help='validation run: hide this fraction of the high-confidence string pairs from the '
                         'string phase, rerun, and report how the other signals re-match them (no TSV written)')
    ap.add_argument('--seed', type=int, default=1)
    a = ap.parse_args()
    pc, gc = ffre.PC(), ffre.GC()
    if a.holdout:
        return holdout_run(pc, gc, a)
    m = Matcher(pc, gc, a.v)
    m.run()
    rep = []
    P = rep.append
    # ---- write TSV
    rows = []
    for g, p in m.M.items():
        conf, ev, ph = m.info[g]
        nm = gc.funcs[g]['name']
        rows.append((g, nm, ffre.demangle(nm), p, conf, ev))
    rows.sort()
    with open(a.out, 'w') as f:
        f.write('gc_name\tgc_demangled\tgc_addr\tpc_addr\tconfidence\tevidence\n')
        for g, nm, dm, p, conf, ev in rows:
            f.write('%s\t%s\t%08x\t0x%06x\t%s\t%s\n' % (nm, dm.replace('\t', ' '), g, p, conf, ev.replace('\t', ' ')))
    # ---- report
    cnt = collections.Counter(m.info[g][0] for g in m.M)
    byph = collections.Counter((m.info[g][2], m.info[g][0]) for g in m.M)
    ngc = len(gc.funcs)
    nnoise = sum(1 for g in gc.funcs if g in m.gnoise)
    P('GC functions (FUNC symbols with size): %d; PC functions (Ghidra): %d' % (ngc, len(pc.funcs)))
    P('Shared string vocabulary: %d strings' % len(m.vocab))
    P('Size band log2(gc/pc): median %.2f, p10 %.2f, p90 %.2f (from %d multi-string pairs); band %.2f..%.2f'
      % (m.size_stats[1], m.size_stats[2], m.size_stats[3], m.size_stats[0], m.band[0], m.band[1]))
    P('vtable classes used %d (+%d with slot gaps), rejected %d' % (m.vt_classes_used, m.vt_classes_gapped, len(m.vt_classes_rejected)))
    P('Matched GC functions: %d (high %d, medium %d, low %d) = %.1f%% of GC functions'
      % (len(m.M), cnt['high'], cnt['medium'], cnt['low'], 100.0 * len(m.M) / ngc))
    P('Distinct PC functions named (high+medium): %d of %d'
      % (len({p for g, p in m.M.items() if m.info[g][0] != 'low'}), len(pc.funcs)))
    for ph in ('strings', 'vtables', 'callgraph', 'order', 'constants'):
        P('  %-10s high %5d  medium %5d  low %5d' % (ph, byph[(ph, 'high')], byph[(ph, 'medium')], byph[(ph, 'low')]))
    P('  demoted by final re-check: %d' % m.phase_counts['demoted'])
    # ---- ground truth
    P('')
    P('Ground truth (%d pairs from finished format work):' % len(GROUND_TRUTH))
    ok = wrong = miss = expl = 0
    for pcaddr, gx, src in GROUND_TRUTH:
        if src.startswith('RELATED'):
            g = gc_lookup(gc, gx)
            got = m.M.get(g)
            others = [gc.funcs[x]['name'] for x in m.Minv.get(pcaddr, ())]
            P('  PC 0x%06x  GC %08x %-45s EXPLAINED (not a 1:1 pair): map has GC->%s, PC->%s'
              % (pcaddr, g, ffre.short_demangled(ffre.demangle(gc.funcs[g]['name']))[:45],
                 ('0x%06x' % got) if got else 'none', ','.join(others) or 'none'))
            P('      ' + src[8:])
            expl += 1
            continue
        g = gc_lookup(gc, gx)
        gname = gc.funcs[g]['name'] if g in gc.funcs else str(gx)
        got = m.M.get(g)
        if got is None:
            st = 'MISSING'
            miss += 1
            # what does the PC side map to?
            others = [gc.funcs[x]['name'] for x in m.Minv.get(pcaddr, ())]
            extra = (' (PC fn matched to %s)' % ','.join(others)) if others else ''
        elif got == pcaddr:
            st = 'OK [%s]' % m.info[g][0]
            ok += 1
            extra = ' ' + m.info[g][1]
        else:
            st = 'WRONG -> 0x%06x [%s]' % (got, m.info[g][0])
            wrong += 1
            extra = ' ' + m.info[g][1]
        P('  PC 0x%06x  GC %08x %-45s %s%s' % (pcaddr, g or 0, ffre.short_demangled(ffre.demangle(gname))[:45], st, extra[:110]))
    P('  correct %d, wrong %d, missing %d, explained (doc pairs a related function) %d' % (ok, wrong, miss, expl))
    P('  spot checks from the PPO script notes (GC side not named in the docs):')
    for pcaddr in (0x5f56f0, 0x5ff2b0):
        for g in sorted(m.Minv.get(pcaddr, ())):
            P('    PC 0x%06x (%s) -> GC %08x %s [%s] %s' % (pcaddr, 'script VM' if pcaddr == 0x5f56f0 else 'PPO loader', g,
                                                       ffre.short_demangled(ffre.demangle(gc.funcs[g]['name'])),
                                                       m.info[g][0], m.info[g][1][:70]))
    # ---- agreement between independent signals (a precision proxy)
    P('')
    P('Signal agreement - a precision proxy (did another signal propose the same PC function?):')
    SIG = {'strings': 'str', 'vtables': 'vt', 'callgraph': 'cg', 'order': 'order', 'constants': 'const'}
    for ph in ('strings', 'vtables', 'callgraph', 'order', 'constants'):
        for conf in ('high', 'medium', 'low'):
            agree = disagree = 0
            for g, p in m.M.items():
                c, ev, phase = m.info[g]
                if phase != ph or c != conf:
                    continue
                other = {pp for pp, sig in m.proposals[g] if sig != SIG[ph]}
                if not other:
                    continue
                if p in other:
                    agree += 1
                else:
                    disagree += 1
            if agree + disagree:
                P('  %-10s %-6s agree %5d  disagree %4d  (%.1f%%)' % (ph, conf, agree, disagree, 100.0 * agree / (agree + disagree)))
    P('')
    P('Call-graph consistency of the final map (matched callee/caller edges of a pair that land on')
    P('callees/callers of its PC function; independent of the signal for strings/vtables/constants):')
    for ph in ('strings', 'vtables', 'callgraph', 'order', 'constants'):
        for conf in ('high', 'medium', 'low'):
            A = T = n = bad = 0
            for g, p in m.M.items():
                c, ev, phase = m.info[g]
                if phase != ph or c != conf:
                    continue
                a1, t1 = m.callee_consistency(g, p)
                a2, t2 = m.caller_consistency(g, p)
                if t1 + t2:
                    n += 1
                    A += a1 + a2
                    T += t1 + t2
                    if (a1 + a2) * 2 < (t1 + t2):
                        bad += 1
            if T:
                P('  %-10s %-6s pairs %5d  edges agree %6d/%6d (%.1f%%)  pairs with <50%% agreement %d'
                  % (ph, conf, n, A, T, 100.0 * A / T, bad))
    text = '\n'.join(rep)
    print(text)
    if a.report:
        open(a.report, 'w').write(text + '\n')
    print('wrote %s (%d rows)' % (a.out, len(rows)), file=sys.stderr)


if __name__ == '__main__':
    main()
